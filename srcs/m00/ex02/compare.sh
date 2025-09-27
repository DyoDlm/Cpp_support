executable=try
originalLog=19920104_091532.log

make re

./$executable > myLog

diff $originalLog myLog > dif


