/***************************************************************************
 *   Copyright (C) 2004 by Janek Kozicki                                   *
 *   cosurgi@berlios.de                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "NullGUI.hpp"
#include "NonConnexBody.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/filesystem/convenience.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

NullGUI::NullGUI ()
{
	interval = 100;
	progress = false;
	snapshotInterval = -1;
	snapshotName = "";
	maxIteration = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

NullGUI::~NullGUI()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void NullGUI::help()
{
	cout <<
"\nYet Another Dynamic Engine, pre-alpha. NullGUI frontend.\n\
\n\
	-H		- print this help.\n\
\n\
    user feedback:\n\
	-v number	- specify iteration INTERVAL in which other tasks are\n\
			  performed, default is set to 100.\n\
	-p		- print progress information every INTERVAL iteration\n\
			  so you see that calculations are going on.\n\
\n\
    input:\n\
	-f name		- specify filename to load.\n\
\n\
    output:\n\
	-s number	- if specified, a snapshot is saved every 'number'\n\
			  INTERVALs. Eg. if INTERVAL is 100, and 'number' is 5,\n\
			  you will have a snpashot every 500th iteration.\n\
	-S name		- specify base filename of snapshot. Defaults to input\n\
			  filename. Filename has appended iteration number.\n\
\n\
    options:\n\
	-m number	- specify maximum number of iterations\n\
			  ( 0 = unlimited, tested every INTERVAL iteration).\n\
	-t number	- set time step in seconds (FIXME - inside .xml)\n\
	-g number	- set gravity (FIXME - inside .xml)\n\
\n";
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

int NullGUI::run(int argc, char** argv)
{

	int ch;
	opterr = 0;
	while( ( ch = getopt(argc,argv,"Hf:s:S:v:pm:t:g:") ) != -1)
		switch(ch)
		{
			case 'H'	: help(); 						return 1;
			case 'v'	: interval = lexical_cast<int>(optarg);			break;
			case 'p'	: progress = true;					break;
			case 'f'	: Omega::instance().setSimulationFileName(optarg);
					  if(snapshotName.size() == 0 ) snapshotName = optarg;	break;
			case 's'	: snapshotInterval = lexical_cast<int>(optarg);		break;
			case 'S'	: snapshotName = optarg;				break;
			case 'm'	: maxIteration = lexical_cast<long int>(optarg);	break;
			case 't'	: Omega::instance().setTimeStep
						(lexical_cast<double>(optarg));			break;
			case 'g'	: Omega::instance().setGravity
						(Vector3r(0,-lexical_cast<Real>(optarg),0));	break;
			default		: break;
		}
	return loop();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

int NullGUI::loop()
{
        long int& iter = Omega::instance().currentIteration; // FIXME : public variable :-P~
	Omega::instance().loadSimulation();
	cerr << "Starting computation of file: " << Omega::instance().getSimulationFileName() << endl;

	if( maxIteration == 0)
		cerr << "No maxiter specified, computations will run forever, to set it, use flag -m\n";
	else
		cerr << "Computing " << maxIteration << " iterations\n";

	cerr << "Using timestep: " << Omega::instance().getTimeStep() << endl;

	filesystem::path p(snapshotName);
	snapshotName = filesystem::basename(p);
	if( snapshotInterval != -1 )
		cerr 	<< "Saving snapshot every " << snapshotInterval*interval << " iterations, \n"
			<< "to filename: " << snapshotName << "_[0-9]" << endl;

	long int intervals = 0;
	while(1)
	{
		Omega::instance().rootBody->moveToNextTimeStep();
		//Omega::instance().incrementCurrentIteration();
		++iter;
		Omega::instance().incrementSimulationTime();

		if( iter % interval == 0 )
		{
			++intervals;

			// print progress...
			if(progress)
				cerr << "iteration: " << iter << endl;

			// save snapshot
			if( ( snapshotInterval != -1 ) && (intervals % snapshotInterval == 0) )
			{
				cerr << "saving snapshot: " << snapshotName + "_" + lexical_cast<string>(iter) + ".xml\n";
				IOManager::saveToFile("XMLManager",
				"../data/" + snapshotName + "_" + lexical_cast<string>(iter) + ".xml",
				"rootBody", Omega::instance().rootBody);
			}

			// finish computation
			if( ( maxIteration !=0 ) &&  (iter > maxIteration) )
			{
				cerr << "Calc finished at: " << iter << endl;
				exit(0);
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////