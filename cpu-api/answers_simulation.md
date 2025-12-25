# Answers (Simulation)

## 1. 
  - a - b
  - a - b (- c)
  - a - b
  - a - b (- d)
  - a - b - (-d) (-e)

## 2. 
Becomes longer and more complex

## 3. 
Yes. Not typing it lol

## 4.
When c exits, the processes d & e becomes orphaned. As such, they are now under the root process.

With the `-R` flag, `local_reparent` becomes `True`, and thus d & e become under process `b`

Usually, when processes are orphaned, the `init` or `PID: 1` process takes over it.

## 5.
Yes. Again, won't write it here.

## 6.
Yes, but situations you can't tell:
- orphaning processes, because processes can just be forked from `init` process, and look the same as orphaned processes
