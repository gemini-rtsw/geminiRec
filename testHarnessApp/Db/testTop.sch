[schematic2]
uniq 1
[tools]
[detail]
[cell use]
use ba200tr 0 0 100 0 ba200tr#1
xform 0 800 600
use testApply 608 785 100 0 testApply#2
xform 0 424 848
p 344 1006 100 0 1 set0:top ${test}
p 595 975 100 0 1 set1:CAR_IDLE 0
p 597 941 100 0 1 set2:CAR_BUSY 2
p 595 904 100 0 1 set3:CAR_ERROR 3
p 600 871 100 0 1 set4:CAD_MARK 0
p 603 839 100 0 1 set5:CAD_STOP 4
p 125 977 100 0 1 set6:m2 grtM2:
p 608 810 100 0 1 set7:CAD_START 3
p 131 953 100 0 1 set8:ag grtAG:
p 133 933 100 0 1 set9:mc grtMC:
p 128 904 100 0 1 set10:cr grtCR:
p 131 882 100 0 1 set11:ao grt:AO:
p 133 864 100 0 1 set12:m1 grtM1:
p 131 844 100 0 1 set13:ec grtEC:
p 135 823 100 0 1 set14:ws grt:WS:
p 130 803 100 0 1 set15:gp grt:GP:
p 124 788 100 0 1 set16:sad grt:SAD:
p 119 772 100 0 1 set17:pwfs1 grtP1:
p 116 754 100 0 1 set18:pwfs2 grtP2:
p 112 737 100 0 1 set19:hrwfs grtHR:
p 112 721 100 0 1 set20:oiwfs grtOI:
p 114 700 100 0 1 set21:nici grtNICI:
use testInterlock 688 496 100 0 testInterlock#4
xform 0 848 592
p 817 714 100 0 1 set0:top ${test}
p 823 693 100 0 1 set1:sad grt:SAD:
[comments]
