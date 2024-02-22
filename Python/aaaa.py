import random
import math

cities = {
    1: (-810, 735),
    2: (-438, 534),
    3: (-64, -288),
    4: (-472, -621),
    5: (239, -359),
    6: (631, 287),
    7: (20, -335),
    8: (-969, -501),
    9: (495, -560),
    10: (-67, 667),
    11: (-727, -671),
    12: (-577, 846),
    13: (-867, 627),
    14: (833, -827),
    15: (-582, 42),
    16: (-79, 242),
    17: (-818, 476),
    18: (-591, -614),
    19: (644, 89),
    20: (-603, 109),
    21: (287, 376),
    22: (509, -280),
    23: (6, 638),
    24: (-245, -55),
    25: (-823, -463),
    26: (-756, 418),
    27: (703, 907),
    28: (705, -461),
    29: (-387, -231),
    30: (-385, -711),
    31: (-815, 448),
    32: (550, 558),
    33: (-990, -561),
    34: (-695, -122),
    35: (993, 493),
    36: (-124, -631),
    37: (895, 782),
    38: (353, -786),
    39: (-433, -634),
    40: (-343, -86),
    41: (-224, -700),
    42: (-435, -316),
    43: (534, 183),
    44: (-808, -173),
    45: (604, 337),
    46: (508, -877),
    47: (509, 916),
    48: (244, 99),
    49: (-160, -216),
    50: (295, 407),
    51: (940, -642),
    52: (-19, -566),
    53: (-100, 515),
    54: (763, 36),
    55: (46, 886),
    56: (946, 913),
    57: (593, -919),
    58: (-132, -924),
    59: (-449, 994),
    60: (351, -314),
    61: (183, -999),
    62: (-628, -206),
    63: (17, 76),
    64: (834, 888),
    65: (-550, -603),
    66: (-631, 425),
    67: (-67, -5),
    68: (-222, 205),
    69: (221, 301),
    70: (1, -92),
    71: (410, 922),
    72: (729, 388),
    73: (-63, -562),
    74: (-309, -701),
    75: (332, -607),
    76: (-831, -216),
    77: (486, -265),
    78: (-517, -734),
    79: (-514, -359),
    80: (176, -69),
    81: (435, -387),
    82: (517, -601),
    83: (958, -717),
    84: (63, -56),
    85: (570, 37),
    86: (354, -223),
    87: (-79, 264),
    88: (-245, -239),
    89: (-559, -562),
    90: (3, -289),
    91: (415, 90),
    92: (-503, -663),
    93: (-933, -398),
    94: (-83, 852),
    95: (484, -794),
    96: (656, 580),
    97: (-933, 84),
    98: (-995, -779),
    99: (-503, 809),
    100: (-492, -886),
    101: (-399, 199),
    102: (323, 346),
    103: (-242, 534),
    104: (-599, 523),
    105: (227, 456),
    106: (258, 372),
    107: (76, 35),
    108: (740, 860),
    109: (466, 828),
    110: (-718, -268),
    111: (364, 859), 
    112: (910, -202),
    113: (-572, -510),
    114: (-532, -604),
    115: (189, -691),
    116: (515, -339),
    117: (386, -433),
    118: (-862, 498),
    119: (642, -116),
    120: (911, -619),
    121: (-801, -326),
    122: (27, -317),
    123: (445, 213),
    124: (573, 411),
    125: (899, -875),
    126: (376, -404),
    127: (167, -197),
    128: (618, 915),
    129: (699, -522),
    130: (991, -840),
    131: (291, 186),
    132: (180, -925),
    133: (-399, -814),
    134: (428, -745),
    135: (-364, -306),
    136: (-653, -764),
    137: (26, 354),
    138: (-422, 301),
    139: (-856, -570),
    140: (-312, -457),
    141: (381, -277),
    142: (-899, 428),
    143: (978, 558),
    144: (-639, 754),
    145: (216, -871),
    146: (-369, -66),
    147: (558, -998),
    148: (-678, -422),
    149: (221, -642),
    150: (382, 633),
    151: (251, -263),
    152: (-285, -18),
    153: (539, 681),
    154: (-416, 547),
    155: (-577, 642),
    156: (-647, 145),
    157: (941, -869),
    158: (-764, 900),
    159: (-24, 134),
    160: (532, -392),
    161: (377, -635),
    162: (856, 583),
    163: (-950, -220),
    164: (-590, -886),
    165: (-988, -162),
    166: (-856, -876),
    167: (833, 387),
    168: (679, -220),
    169: (-454, -233),
    170: (681, 51),
    171: (-752, 657),
    172: (575, -133),
    173: (-417, 398),
    174: (988, -185),
    175: (-363, 826),
    176: (-684, -609),
    177: (-313, 683),
    178: (826, -609),
    179: (255, 206),
    180: (-289, 492),
    181: (877, 804),
    182: (854, -2),
    183: (-712, -479),
    184: (473, -916),
    185: (-796, 556),
    186: (821, -988),
    187: (758, -378),
    188: (277, -699),
    189: (-112, -888),
    190: (818, 881),
    191: (-340, -565),
    192: (-940, 588),
    193: (263, -146),
    194: (576, 329),
    195: (398, -622),
    196: (-392, -360),
    197: (221, 282),
    198: (153, 39),
    199: (-532, 330),
    200: (54, 407),
    201: (-287, -118),
    202: (-813, -275),
    203: (-516, 368),
    204: (475, 134),
    205: (201, 763),
    206: (69, -343),
    207: (501, 35),
    208: (916, 634),
    209: (-833, -680),
    210: (228, 723),
    211: (721, 340),
    212: (72, -417),
    213: (-53, 357),
    214: (111, -764),
    215: (875, 319),
    216: (699, -405),
    217: (-339, 853),
    218: (735, -990),
    219: (665, -72),
    220: (-241, -60),
    221: (-549, 140),
    222: (260, 452),
    223: (781, -715),
    224: (-116, -501),
    225: (-191, 252),
    226: (55, 725),
    227: (71, -364),
    228: (-790, -112),
    229: (-745, -935),
    230: (847, 163),
    231: (75, -218),
    232: (-506, -342),
    233: (-164, 257),
    234: (-890, 277),
    235: (-327, 681),
    236: (882, -771),
    237: (960, -228),
    238: (-370, -118),
    239: (-537, 111),
    240: (819, -979),
    241: (-826, -496),
    242: (665, 576),
    243: (795, 93),
    244: (-153, 463),
    245: (127, -523),
    246: (-381, 161),
    247: (-379, -959),
    248: (-951, -851),
    249: (650, -171),
    250: (802, 899),
    251: (-273, 351),
    252: (-646, -653),
    253: (-694, -982),
    254: (457, -811),
    255: (-775, -258),
    256: (-713, -496),
    257: (93, -817),
    258: (-395, 824),
    259: (111, -691),
    260: (352, 826),
    261: (-865, -990),
    262: (8, -138),
    263: (-441, 244),
    264: (-458, 570),
    265: (-163, 940),
    266: (175, -270),
    267: (760, 547),
    268: (617, 985),
    269: (669, -139),
    270: (564, -568),
    271: (-583, -405),
    272: (530, 385),
    273: (437, 80),
    274: (-773, -971),
    275: (128, 377),
    276: (337, -10),
    277: (914, -733),
    278: (-115, -114),
    279: (316, -659),
    280: (-447, 725),
    281: (-360, -110),
    282: (373, -847),
    283: (751, 406),
    284: (-715, -280),
    285: (337, -199),
    286: (736, -727),
    287: (-238, 76),
    288: (-569, 963),
    289: (-701, -144),
    290: (-635, 71),
    291: (-253, 658),
    292: (-87, -109),
    293: (752, 454),
    294: (662, 156),
    295: (116, -91),
    296: (460, 817),
    297: (-726, 761),
    298: (181, 293),
    299: (225, -114),
    300: (-625, 724),
    301: (412, -548),
    302: (793, 108),
    303: (485, -71),
    304: (-13, 408),
    305: (435, -950),
    306: (759, 77),
    307: (-942, -936),
    308: (-727, -215),
    309: (-604, 966),
    310: (-882, -380),
    311: (888, -848),
    312: (-977, 479),
    313: (108, 344),
    314: (-680, 171),
    315: (897, -691),
    316: (-920, -425),
    317: (642, 973),
    318: (49, -92),
    319: (489, 221),
    320: (-746, -437),
    321: (260, -95),
    322: (36, 449),
    323: (427, 53),
    324: (-611, 240),
    325: (255, 794),
    326: (802, 312),
    327: (-196, -83),
    328: (509, -903),
    329: (567, -943),
    330: (-80, -66),
    331: (946, -937),
    332: (99, -279),
    333: (442, -363),
    334: (-741, -923),
    335: (-969, -704),
    336: (789, 457),
    337: (216, 669),
    338: (-26, -527),
    339: (347, -849),
    340: (-129, 437),
    341: (730, 809),
    342: (19, -847),
    343: (-364, -64),
    344: (849, -318),
    345: (-34, -803),
    346: (-179, -229),
    347: (-722, -731),
    348: (3, 280),
    349: (-998, -998),
    350: (90, -277),
    351: (-221, 314),
    352: (-922, -9),
    353: (860, 891),
    354: (-499, -964),
    355: (447, 939),
    356: (104, -745),
    357: (124, -43),
    358: (96, 920),
    359: (735, 954),
    360: (301, 112),
    361: (-872, -335),
    362: (109, 674),
    363: (680, 383),
    364: (-107, 861),
    365: (750, 578),
    366: (-378, -512),
    367: (242, 570),
    368: (-858, 705),
    369: (568, -867),
    370: (971, -182),
    371: (-108, 741),
    372: (855, 244),
    373: (-536, 956),
    374: (655, -156),
    375: (224, 948),
    376: (-608, -910),
    377: (-479, -335),
    378: (-736, -358),
    379: (-478, 233),
    380: (-585, -547),
    381: (-245, 831),
    382: (-728, -596),
    383: (-50, -190),
    384: (474, 446),
    385: (-845, -467),
    386: (-776, 422),
    387: (-964, -478),
    388: (-410, 593),
    389: (-436, -690),
    390: (786, 782),
    391: (93, -515),
    392: (-272, -170),
    393: (378, -469),
    394: (-812, -20),
    395: (-197, -20),
    396: (-668, -913),
    397: (-55, -461),
    398: (-687, 30),
    399: (773, -767),
    400: (-902, 280),
    401: (-628, -55),
    402: (440, -585),
    403: (889, 209),
    404: (395, -588),
    405: (88, -941),
    406: (299, -652),
    407: (-232, 457),
    408: (483, 174),
    409: (-633, -670),
    410: (-210, -631),
    411: (200, 901),
    412: (414, -525),
    413: (-848, 256),
    414: (60, -271),
    415: (557, -35),
    416: (589, -909),
    417: (221, 31),
    418: (294, 420),
    419: (473, -928),
    420: (-571, -474),
    421: (-344, -427),
    422: (797, 397),
    423: (-936, 98),
    424: (264, -342),
    425: (-308, -908),
    426: (680, -685),
    427: (-758, 319),
    428: (-91, 896),
    429: (25, -187),
    430: (212, -722),
    431: (-524, -974),
    432: (-790, -288),
    433: (629, -536),
    434: (88, -852),
    435: (884, -145),
    436: (194, -488),
    437: (-897, -170),
    438: (-884, 782),
    439: (-813, 416),
    440: (90, 544),
    441: (908, -176),
    442: (-467, -566),
    443: (135, -865),
    444: (770, 760),
    445: (753, -683),
    446: (-156, -348),
    447: (404, -628),
    448: (768, -119),
    449: (-934, -339),
    450: (950, 474),
    451: (3, -50),
    452: (-90, 148),
    453: (-273, 765),
    454: (892, 713),
    455: (-461, -922),
    456: (-650, 337),
    457: (9, -554),
    458: (712, 48),
    459: (591, 478),
    460: (-887, -940),
    461: (183, 194),
    462: (800, -687),
    463: (-914, 551),
    464: (-786, 709),
    465: (515, 330),
    466: (-278, -684),
    467: (295, 549),
    468: (930, 581),
    469: (36, -576),
    470: (968, 8),
    471: (901, -448),
    472: (-463, 492),
    473: (905, 989),
    474: (-381, -776),
    475: (143, 56),
    476: (-260, -108),
    477: (546, -873),
    478: (479, -934),
    479: (633, -274),
    480: (-166, 122),
    481: (-452, 877),
    482: (932, 400),
    483: (-990, 578),
    484: (587, -271),
    485: (-168, 996),
    486: (431, -638),
    487: (-532, -386),
    488: (906, -495),
    489: (122, 242),
    490: (285, -286),
    491: (450, -989),
    492: (408, 151),
    493: (-946, -246),
    494: (175, 904),
    495: (881, 40),
    496: (-818, 612),
    497: (-926, 640),
    498: (88, 4),
    499: (-697, -524),
    500: (-83, 939),
    501: (-747, 596),
    502: (135, 34),
    503: (8, -692),
    504: (471, 431),
    505: (142, -637),
    506: (896, -930),
    507: (580, 421),
    508: (977, -289),
    509: (-183, 133),
    510: (-967, -191),
    511: (-199, -652),
    512: (312, -153),
    513: (-558, 257),
    514: (-63, -932),
    515: (288, 962),
    516: (-638, 100),
    517: (-914, 908),
    518: (318, -3),
    519: (594, -752),
    520: (-708, 827),
    521: (-987, 294),
    522: (341, 819),
    523: (826, -602),
    524: (-718, -947),
    525: (-899, 139),
    526: (850, -211),
    527: (-140, -31),
    528: (-149, 382),
    529: (-720, -664),
    530: (-819, -900),
    531: (-751, 308),
    532: (239, 320),
    533: (980, -833),
    534: (-506, 323),
    535: (-57, 140),
    536: (356, -548),
    537: (413, -929),
    538: (-553, -193),
    539: (-333, 61),
    540: (659, -105),
    541: (772, -439),
    542: (-670, -673),
    543: (-994, -757),
    544: (-386, -610),
    545: (933, 542),
    546: (-755, -740),
    547: (502, -235),
    548: (326, -102),
    549: (88, -882),
    550: (436, 203),
    551: (586, 354),
    552: (-487, 596),
    553: (913, 490),
    554: (726, 434),
    555: (720, -510),
    556: (488, 475),
    557: (839, 64),
    558: (273, -261),
    559: (783, -785),
    560: (-378, 281),
    561: (607, -896),
    562: (-759, -737),
    563: (688, -882),
    564: (-158, 844),
    565: (-815, 309),
    566: (607, -892),
    567: (114, 733),
    568: (-882, 846),
    569: (597, -940),
    570: (-342, -650),
    571: (520, -31),
    572: (-938, -335),
    573: (-108, 960),
    574: (747, 162),
    575: (-830, 249),
    576: (-988, 443),
    577: (10, 465),
    578: (381, 901),
    579: (960, -642),
    580: (-308, -981),
    581: (315, 84),
    582: (221, -112),
    583: (431, -832),
    584: (-325, -317),
    585: (966, 184),
    586: (-993, 147),
    587: (850, -149),
    588: (-865, -766),
    589: (86, -485),
    590: (971, 753),
    591: (290, -855),
    592: (647, -677),
    593: (-699, -991),
    594: (474, -7),
    595: (-789, 795),
    596: (519, -548),
    597: (255, 315),
    598: (449, 897),
    599: (245, 446),
    600: (914, -834),
    601: (-88, 174),
    601: (-88, 174),
    601: (-88, 174),
    602: (987, -199),
    603: (336, 200),
    604: (941, -929),
    605: (-633, 594),
    606: (-851, -983),
    607: (198, -786),
    608: (874, 751),
    609: (-321, -677),
    610: (978, 828),
    611: (-124, 24),
    612: (736, 874),
    613: (-911, -742),
    614: (627, -312), 
    615: (31, 996),
    616: (-151, 295),
    617: (-933, -824),
    618: (-652, -964),
    619: (-251, -960),
    620: (-140, -97),
    621: (-891, -384),
    622: (-366, 739),
    623: (344, 580),
    624: (232, -987),
    625: (-651, -214),
    626: (-41, 340),
    627: (-652, 750),
    628: (724, -491),
    629: (395, -677),
    630: (324, 629),
    631: (-624, 124),
    632: (-570, -726),
    633: (-597, 274),
    634: (-982, -71),
    635: (480, 849),
    636: (-738, 692),
    637: (164, 168),
    638: (-89, -136),
    639: (900, -757),
    640: (403, -234),
    641: (-71, -773),
    642: (-781, -70),
    643: (-727, -111),
    644: (623, 205),
    645: (430, 985),
    646: (-191, 548),
    647: (-429, 103),
    648: (-66, -25),
    649: (790, -989),
    650: (-640, -509),
    651: (-745, -683),
    652: (-647, -678),
    653: (303, 352),
    654: (513, 968),
    655: (937, -881),
    656: (77, -889),
    657: (840, 807),
    658: (-583, 255),
    659: (-369, 180),
    660: (-47, -170),
    661: (-60, -698),
    662: (-609, -700),
    663: (376, 953),
    664: (-777, 765),
    665: (547, -925),
    666: (-76, 774),
    667: (759, -623),
    668: (886, 969),
    669: (678, 807),
    670: (718, -121),
    671: (-560, 540),
    672: (715, -711),
    673: (-531, 122),
    674: (627, 994),
    675: (-618, 360),
    676: (95, -263),
    677: (-750, -120),
    678: (112, -282),
    679: (935, 367),
    680: (-265, 574),
    681: (-297, 965),
    682: (268, -453),
    683: (-883, 830),
    684: (748, -338),
    685: (450, -241),
    686: (-869, -981),
    687: (352, -649),
    688: (-570, -388),
    689: (532, -372),
    690: (334, 612),
    691: (656, -259),
    692: (833, -100),
    693: (569, 106),
    694: (-753, -792),
    695: (562, -517),
    696: (724, -610),
    697: (618, 278),
    698: (6, 874),
    699: (582, -364),
    700: (893, 218),
    701: (859, -895),
    702: (930, 919),
    701: (859, -895),
    702: (930, 919),
    703: (929, -845),
    704: (422, -559),
    705: (-279, -333),
    706: (28, -188),
    707: (-493, -645),
    708: (-384, -690),
    709: (79, 392),
    710: (-596, -312),
    711: (92, 588),
    712: (646, 919),
    713: (252, 632),
    714: (-556, -57),
    715: (-807, 606),
    716: (931, -64),
    717: (261, -642),
    718: (-844, -197),
    719: (-802, 438),
    720: (328, -19),
    721: (210, 979),
    722: (132, -872),
    723: (-890, 389),
    724: (750, 639),
    725: (504, 938),
    726: (438, -761),
    727: (-609, -252),
    728: (318, 67),
    729: (426, -884),
    730: (-952, -365),
    731: (464, 456),
    732: (376, 262),
    733: (150, -131),
    734: (-568, 6),
    735: (846, 694),
    736: (271, 591),
    737: (-652, 589),
    738: (-266, -429),
    739: (-108, -615),
    740: (968, 284),
    741: (811, -368),
    742: (-383, 241),
    743: (608, -725),
    744: (-676, 768),
    745: (-958, 817),
    746: (-933, 636),
    747: (-20, -263),
    748: (-260, -611),
    749: (-979, -45),
    750: (527, 842),
    751: (558, 99),
    752: (432, -761),
    753: (-622, 948),
    754: (343, 784),
    755: (-380, 548),
    756: (867, 997),
    757: (-829, 202),
    758: (825, -563),
    759: (-968, 108),
    760: (-987, 628),
    761: (-759, 102),
    762: (-248, -271),
    763: (-454, 384),
    764: (-620, 236),
    765: (-182, -286),
    766: (-468, 16),
    767: (74, 926),
    768: (906, -471),
    769: (-790, 224),
    770: (-224, 782),
    771: (368, 815),
    772: (232, -116),
    773: (979, -357),
    774: (15, 152),
    775: (693, -307),
    776: (-396, -810),
    777: (-890, -971),
    778: (-259, -877),
    779: (172, -267),
    780: (-295, -72),
    781: (-965, 849),
    782: (182, -524),
    783: (771, -314),
    784: (-234, 377),
    785: (-78, 314),
    786: (-802, 297),
    787: (129, -743),
    788: (-106, -276),
    789: (388, -785),
    790: (-351, 80),
    791: (-108, -930),
    792: (614, -257),
    793: (109, -768),
    794: (-882, -956),
    795: (867, -813),
    796: (709, 268),
    797: (441, 718),
    798: (540, -792),
    799: (-76, 296),
    800: (-835, 452),
    801: (-269, 407),
    802: (833, -285),
    803: (65, 327),
    804: (234, -648),
    805: (921, -650),
    806: (918, 376),
    807: (-810, 65),
    808: (811, -601),
    809: (187, 891),
    810: (-816, 973),
    811: (-4, 277),
    812: (993, -301),
    813: (695, -623),
    814: (980, 385),
    815: (-258, 606),
    816: (846, -488),
    817: (-206, -473),
    818: (772, 666),
    819: (-703, 828),
    820: (-799, -966),
    821: (220, 924),
    822: (-661, -863),
    823: (331, 294),
    824: (-685, 682),
    825: (106, -639),
    826: (105, 728),
    827: (850, 403),
    828: (470, 2),
    829: (678, 848),
    830: (506, 1000),
    831: (-60, -273),
    832: (536, 609),
    833: (-529, -974),
    834: (868, -849),
    835: (-819, 63),
    836: (14, 684),
    837: (-757, 906),
    838: (589, -151),
    839: (303, -927),
    840: (-766, 713),
    841: (176, -101),
    842: (176, -714),
    843: (-770, 4),
    844: (704, -327),
    845: (670, -235),
    846: (769, -540),
    847: (-119, -215),
    848: (-83, -177),
    849: (-130, -846),
    850: (-347, 814),
    851: (-488, 179),
    852: (-996, -388),
    853: (567, -683),
    854: (-296, -132),
    855: (590, -185),
    856: (-712, -502),
    857: (-720, -91),
    858: (46, 26),
    859: (-663, -711),
    860: (-951, 16),
    861: (541, 813),
    862: (883, 857),
    863: (-724, -810),
    864: (137, 307),
    865: (-783, 572),
    866: (26, 39),
    867: (875, -128),
    868: (615, 595),
    869: (79, 266),
    870: (165, 558),
    871: (666, -323),
    872: (753, 360),
    873: (287, 899),
    874: (-187, -492),
    875: (53, -859),
    876: (823, 286),
    877: (-597, -839),
    878: (-394, -43),
    879: (420, 761),
    880: (421, -94),
    881: (-180, 941),
    882: (-512, -102),
    883: (114, 744),
    884: (765, -58),
    885: (-35, 120),
    886: (232, -524),
    887: (-60, 101),
    888: (-213, 83),
    889: (-849, 53),
    890: (94, -24),
    891: (374, 883),
    892: (-598, 990),
    893: (-10, 753),
    894: (-938, -20),
    895: (-38, 740),
    896: (-498, 341),
    897: (-545, 828),
    898: (54, 915),
    899: (-67, -835),
    900: (-943, -495),
    901: (-270, 430),
    902: (165, 302),
    903: (-995, 732),
    904: (717, 154),
    905: (-714, -660),
    906: (235, -657),
    907: (-596, -73),
    908: (-709, -446),
    909: (-254, 752),
    910: (-810, 70),
    911: (-347, 715),
    912: (186, -637),
    913: (-980, 904),
    914: (-53, 283),
    915: (462, 934),
    916: (260, 610),
    917: (-811, -102),
    918: (788, 279),
    919: (-712, 92),
    920: (523, -752),
    921: (118, 347),
    922: (-151, -654),
    923: (635, 438),
    924: (-662, -52),
    925: (-954, -370),
    926: (378, 534),
    927: (-783, -806),
    928: (-841, 939),
    929: (-86, -128),
    930: (-636, 805),
    931: (-244, 905),
    932: (973, -685),
    933: (-485, -186),
    934: (-831, -231),
    935: (851, 675),
    936: (-925, 55),
    937: (-287, -773),
    938: (845, 18),
    939: (-517, 317),
    940: (779, 94),
    941: (-608, -378),
    942: (897, -161),
    943: (293, 49),
    944: (678, 584),
    945: (809, 789),
    946: (-942, -374),
    947: (893, 991),
    948: (-502, 130),
    949: (415, 543),
    950: (15, 525),
    951: (150, -999),
    952: (856, -276),
    953: (461, -877),
    954: (-690, 16),
    955: (-576, 475),
    956: (-697, 955),
    957: (557, 843),
    958: (781, -329),
    959: (-431, -758),
    960: (-545, -868),
    961: (-616, -965),
    962: (148, -958),
    963: (-671, 156),
    964: (-824, 655),
    965: (841, -936),
    966: (-31, -248),
    967: (949, 192),
    968: (-1000, -792),
    969: (582, -581),
    970: (-3, 805),
    971: (-673, 657),
    972: (-75, -143),
    973: (-394, 212),
    974: (-270, -286),
    975: (-90, -991),
    976: (-677, 215),
    977: (-786, 924),
    978: (750, 9),
    979: (137, -582),
    980: (-66, -524),
    981: (-365, -253),
    982: (-840, -132),
    983: (597, 128),
    984: (916, 468),
    985: (-926, 662),
    986: (-682, 322),
    987: (842, -410),
    988: (-556, 506),
    989: (-217, 565),
    990: (108, -848),
    991: (-352, -468),
    992: (-718, -855),
    993: (318, 756),
    994: (927, -643),
    995: (285, 673),
    996: (390, 717),
    997: (821, 536),
    998: (992, -959),
    999: (-763, -284),
   1000: (-190, -933)
}

def compute_distance(city1, city2):
    x1, y1 = city1
    x2, y2 = city2
    return math.sqrt((x1 - x2)**2 + (y1 - y2)**2)

def total_distance(path):
    total = 0
    for i in range(len(path) - 1):
        total += compute_distance(cities[path[i]], cities[path[i + 1]])
    return total

def mutate(route):
    i, j = random.sample(range(len(route)), 2)
    route[i], route[j] = route[j], route[i]

def crossover(parent1, parent2):
    i, j = sorted(random.sample(range(len(parent1)), 2))
    child = [-1]*len(parent1)
    child[i:j] = parent1[i:j]
    for city in parent2:
        if city not in child:
            for i in range(len(child)):
                if child[i] == -1:
                    child[i] = city
                    break
    return child

POP_SIZE = 50

MAX_GEN = 100

MUTANT_RATE = 0.05

population = [random.sample(list(cities.keys()), len(cities)) for _ in range(POP_SIZE)]

for gen in range(MAX_GEN):
    fitness_values = [total_distance(individual) for individual in population]

    fitness_sum = sum(fitness_values)
    selection_probs = [f/fitness_sum for f in fitness_values]
    parents = random.choices(population, weights=selection_probs, k=POP_SIZE)

    new_population = []
    for i in range(0, POP_SIZE, 2):
        child1 = crossover(parents[i], parents[i+1])
        child2 = crossover(parents[i+1], parents[i])
        if random.random() < MUTANT_RATE:
            mutate(child1)
            mutate(child2)
        new_population.append(child1)
        new_population.append(child2)

    population = new_population

best_individual = min(population, key=total_distance)
print('Best route:', best_individual)
print('Distance:', total_distance(best_individual))