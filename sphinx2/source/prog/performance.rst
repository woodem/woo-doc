Performance issues
===================



Timing
-------

Timing services can be used to determine bottlenecks of a simulation, for the purposes of changing its setup, or improving the c++ code. Woo provides two services to measure time spent in different parts of the code. The first one is on per-engine level, the other on arbitrary fine c++-source level (requiring re-compilation).

In-engine timing
^^^^^^^^^^^^^^^^^

The coarser timing works by merely accumulating numebr of invocations and time (with the precision of the ``clock_gettime`` function) spent in each engine, which can be then post-processed by associated Python module :obj:`woo.timing`. There is the bool variable :obj:`woo.master.timingEnabled <woo.core.Master.timingEnabled>` controlling whether such measurements take place (disabled by default). If the script sets this flag to ``True``::

   woo.master.timingEnabled=True

then the data can be reported in aggregated form by :obj:`woo.timing.stats` and reset to zero using :obj:`woo.timing.reset`. 

.. note:: For legacy reasons, this timing functions operate on the master scene only, which should not be an issue in normal circumstances.

Let's see the output from the :obj:`~woo.pre.horse.FallingHorse` preprocessor::

   Woo [1]: import woo.pre.horse, woo.timing
   Woo [2]: S=woo.master.scene=woo.pre.horse.FallingHorse()()
   Woo [3]: woo.master.timingEnabled=True
   Woo [4]: S.run(500,wait=True)
   Woo [5]: import woo.timing
   Woo [6]: woo.timing.stats()

   Name                                                  Count            Time [ms]        Rel. time [%]
   -----------------------------------------------------------------------------------------------------
   "leapfrog"                                        500                831.3                21.85      
   "collider"                                  (175) 500               1478.2                38.86      
   "contactLoop"                                     500                839.1                22.06      
   "dynDt"                                             5                  6.7                 0.18      
   PyRunner                                           50                 13.0                 0.34      
   PyRunner                                           10                  1.8                 0.05      
   BoxOutlet                                           5                  0.3                 0.01      
   VtkExport                                          12                595.4                15.65      
   "flowAnalysis"                                     13                 25.8                 0.68      
   "tracer"                                           25                 12.7                 0.33      
   TOTAL                                                               3804.2               100.00      

Interpretation of the table is straight-forward. Total running time was 3.8s, out of which ≈20% was motion integration (labels are shown for engines which do have a label, and are thus accessible as e.g. ``S.lab.leapfrog``), ≈40% collision detection, ≈20% contact resolution, ≈15% export to VTK and then negligible amount of time for the rest. The number ``(175)`` for collider signifies how many times it did the full run (as opposed only to checking that it does not have to run in that step).

In-engine and in-functor timing
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. note:: Refer to `Yade documentation on timing <https://yade-dem.org/doc/prog.html#timing>`__ for details; there has been changes but those documents should still be useful.


