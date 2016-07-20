[schematic2]
uniq 22
[tools]
[detail]
w 2516 658 100 0 n#1 testSeqCadCarA.testSeqCadCarA#53.STLK 2392 656 2688 656 outhier.OBSSTLK.p
w 784 354 100 0 n#2 testSeqCadCarB.testSeqCadCarB#58.MESS 1248 816 1376 816 1376 352 240 352 240 1392 416 1392 eapply.apply1.INMD
w 784 340 100 0 n#3 testSeqCadCarB.testSeqCadCarB#58.VAL 1248 896 1408 896 1408 336 208 336 208 1424 416 1424 eapply.apply1.INPD
w 1264 308 100 0 n#4 testSeqCadCarA.testSeqCadCarA#53.MESS 2328 816 2400 816 2400 304 176 304 176 1456 416 1456 eapply.apply1.INMC
w 1264 292 100 0 n#5 testSeqCadCarA.testSeqCadCarA#53.VAL 2328 896 2416 896 2416 288 160 288 160 1488 416 1488 eapply.apply1.INPC
w 866 1128 100 0 n#6 eapply.apply1.OCLD 800 1392 864 1392 864 816 1024 816 testSeqCadCarB.testSeqCadCarB#58.ICID
w 882 1184 100 0 n#7 eapply.apply1.OUTD 800 1424 880 1424 880 896 1024 896 testSeqCadCarB.testSeqCadCarB#58.DIR
w 1432 1042 100 0 n#8 eapply.apply1.OCLC 800 1456 896 1456 896 1040 2016 1040 2016 816 2104 816 testSeqCadCarA.testSeqCadCarA#53.ICID
w 1456 1058 100 0 n#9 eapply.apply1.OUTC 800 1488 912 1488 912 1056 2048 1056 2048 896 2104 896 testSeqCadCarA.testSeqCadCarA#53.DIR
w 1320 2356 100 0 n#10 eapply.apply1.INMB 416 1520 208 1520 208 2352 2480 2352 2480 2064 2352 2064 testSeqCadCarB.testSeqCadCarB#59.MESS
w 1320 2322 100 0 n#11 eapply.apply1.INPB 416 1552 240 1552 240 2320 2448 2320 2448 2144 2352 2144 testSeqCadCarB.testSeqCadCarB#59.VAL
w 776 2274 100 0 n#12 eapply.apply1.INPA 416 1616 288 1616 288 2272 1312 2272 1312 2144 1264 2144 testSeqCadCarC.testSeqCadCarC#62.VAL
w 792 2292 100 0 n#13 eapply.apply1.INMA 416 1584 272 1584 272 2288 1360 2288 1360 2064 1264 2064 testSeqCadCarC.testSeqCadCarC#62.MESS
w 1392 1522 100 0 n#14 eapply.apply1.OCLB 800 1520 2032 1520 2032 2064 2128 2064 testSeqCadCarB.testSeqCadCarB#59.ICID
w 1368 1554 100 0 n#15 eapply.apply1.OUTB 800 1552 1984 1552 1984 2144 2128 2144 testSeqCadCarB.testSeqCadCarB#59.DIR
w 850 1904 100 0 n#16 eapply.apply1.OUTA 800 1616 848 1616 848 2144 1040 2144 testSeqCadCarC.testSeqCadCarC#62.DIR
w 882 1848 100 0 n#17 eapply.apply1.OCLA 800 1584 880 1584 880 2064 1040 2064 testSeqCadCarC.testSeqCadCarC#62.ICID
w 1976 1428 100 0 n#18 eapply.apply1.MESS 800 1680 928 1680 928 1424 3072 1424 outhier.MESS.p
w 1984 1490 100 0 n#19 eapply.apply1.VAL 800 1712 944 1712 944 1488 3072 1488 outhier.VAL.p
w 248 1682 100 0 n#20 inhier.ICID.P 16 1584 128 1584 128 1680 416 1680 eapply.apply1.CLID
w 192 1714 100 0 n#21 inhier.DIR.P 16 1712 416 1712 eapply.apply1.DIR
s 2768 336 100 0 OCS Sequence commands
s 2728 280 100 0 20 Jun 96
s 2688 280 100 0 C
s 2496 248 100 0 P B Taylor
s 2784 392 200 0 Gemini TCS
s 2464 2592 100 0 $Id: testSeqCommands1.sch,v 1.2 1998/11/16 19:10:12 cjm Exp $
[cell use]
use bc200tr -112 120 -100 0 frame
xform 0 1568 1424
use testSeqCadCarC 1064 1720 100 0 testSeqCadCarC#62
xform 0 1160 2000
p 1048 1710 100 0 1 seta:seqcommand init
use outhier 3064 1384 100 0 MESS
xform 0 3056 1424
use outhier 3064 1448 100 0 VAL
xform 0 3056 1488
use outhier 2680 616 100 0 OBSSTLK
xform 0 2672 656
use testSeqCadCarB 2152 1720 100 0 testSeqCadCarB#59
xform 0 2248 2000
p 2128 1710 100 0 1 seta:seqcommand reboot
p 2128 1678 100 0 1 setb:delay 10.0
p 2148 1658 100 0 0 setc:outa 0.0
p 2168 1638 100 0 0 setd:outb 0.0
p 2188 1618 100 0 0 sete:outc 0.0
p 2208 1598 100 0 0 setf:outd 0.0
use testSeqCadCarB 1048 472 100 0 testSeqCadCarB#58
xform 0 1144 752
p 1024 462 100 0 1 seta:seqcommand test
p 1024 430 100 0 1 setb:delay 0.5
p 1226 443 100 0 1 setc:outa 0.0
p 1226 422 100 0 1 setd:outb 0.0
p 1226 398 100 0 1 sete:outc 0.0
p 1230 372 100 0 1 setf:outd 0.0
use testSeqCadCarA 2152 472 100 0 testSeqCadCarA#53
xform 0 2248 752
p 2112 462 100 0 1 seta:seqcommand observe
p 2112 398 100 0 1 setb:delay 0.5
p 2112 430 100 0 1 setc:carname observeC
use inhier 24 1544 100 0 ICID
xform 0 16 1584
use inhier 24 1672 100 0 DIR
xform 0 16 1712
use eapply 440 1080 100 0 apply1
xform 0 608 1440
p 556 1124 100 0 0 DESC:Apply record for OCS sequence commands
[comments]
