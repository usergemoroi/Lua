

// ===== ELF HEADER =====
// ============================
arch     arm
baddr    0x0
binsz    138962248
bintype  elf
bits     64
canary   true
dbglink  libunity.sym.so
injprot  false
class    ELF64
crypto   false
endian   little
havecode true
laddr    0x0
lang     c++
linenum  true
lsyms    true
machine  ARM aarch64
nx       true
os       linux
pic      true
relocs   true
relro    full
rpath    NONE
sanitize false
static   false
stripped false
subsys   linux
va       true


// ===== SECTIONS =====
// ============================
nth paddr            size vaddr           vsize perm flags        type        name
――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――
0   0x00000000        0x0 0x00000000        0x0 ---- 0x7d00000000 NULL
1   0x00000270       0x18 0x00000270       0x18 -r-- 0x7d00000002 NOTE        .note.gnu.build-id
2   0x00000288     0x1b90 0x00000288     0x1b90 -r-- 0x7d00000002 DYNSYM      .dynsym
3   0x00001e18      0x24c 0x00001e18      0x24c -r-- 0x7d00000002 GNU_VERSYM  .gnu.version
4   0x00002064       0x38 0x00002064       0x38 -r-- 0x7d00000002 GNU_VERDEF  .gnu.version_d
5   0x0000209c       0x60 0x0000209c       0x60 -r-- 0x7d00000002 GNU_VERNEED .gnu.version_r
6   0x00002100       0x30 0x00002100       0x30 -r-- 0x7d00000002 GNU_HASH    .gnu.hash
7   0x00002130     0x1363 0x00002130     0x1363 -r-- 0x7d00000002 STRTAB      .dynstr
8   0x00003498  0x10dc910 0x00003498  0x10dc910 -r-- 0x7d00000002 RELA        .rela.dyn
9   0x010dfda8     0x1968 0x010dfda8     0x1968 -r-- 0x7d00000042 RELA        .rela.plt
10  0x010e1740  0x19752f3 0x010e1740  0x19752f3 -r-- 0x7d00000032 PROGBITS    .rodata
11  0x02a56a34   0x1941e4 0x02a56a34   0x1941e4 -r-- 0x7d00000002 PROGBITS    .gcc_except_table
12  0x02beac18   0x2c818c 0x02beac18   0x2c818c -r-- 0x7d00000002 PROGBITS    .eh_frame_hdr
13  0x02eb2da8   0xa63fec 0x02eb2da8   0xa63fec -r-- 0x7d00000002 PROGBITS    .eh_frame
14  0x03916dc0  0x42c10e8 0x0391adc0  0x42c10e8 -r-x 0x7d00200006 PROGBITS    .text
15  0x07bd7eb0     0x1110 0x07bdbeb0     0x1110 -r-x 0x7d00000006 PROGBITS    .plt
16  0x07bd8fc0   0x3e6138 0x07be0fc0   0x3e6138 -rw- 0x7d00000003 PROGBITS    .data.rel.ro
17  0x07fbf0f8      0xed0 0x07fc70f8      0xed0 -rw- 0x7d00000003 INIT_ARRAY  .init_array
18  0x07fbffc8      0x1f0 0x07fc7fc8      0x1f0 -rw- 0x7d00000003 DYNAMIC     .dynamic
19  0x07fc01b8    0xcad90 0x07fc81b8    0xcad90 -rw- 0x7d00000003 PROGBITS    .got
20  0x0808af48      0x890 0x08092f48      0x890 -rw- 0x7d00000003 PROGBITS    .got.plt
21  0x0808b7e0   0x3fabf0 0x080977e0   0x3fabf0 -rw- 0x7d00200003 PROGBITS    .data
22  0x084863d0        0x0 0x08492400   0x325950 -rw- 0x7d00200003 NOBITS      .bss
23  0x084863d0      0x105 0x00000000      0x105 ---- 0x7d00000000 STRTAB      .shstrtab
24  0x084864d5       0x5c 0x00000000       0x5c ---- 0x7d00000000 NOTE        .note.unity
25  0x08486534       0x14 0x00000000       0x14 ---- 0x7d00000000 PROGBITS    .gnu_debuglink


// ===== SYMBOLS =====
// ============================
nth paddr      vaddr      bind   type   size lib name                                      demangled
――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――
289 0x03c220ac 0x03c260ac GLOBAL FUNC   164      JNI_OnLoad
290 0x03c2242c 0x03c2642c GLOBAL FUNC   144      JNI_OnUnload
291 0x03c82ee4 0x03c86ee4 GLOBAL FUNC   204      UnitySendMessage
292 0x03bf85bc 0x03bfc5bc GLOBAL FUNC   12       UnitySwappy_version
293 0x03bf85c8 0x03bfc5c8 GLOBAL FUNC   52       UnitySwappy_injectTracer
1   0x07bd7f10 0x07bdbf10 GLOBAL FUNC   16       imp.__cxa_atexit
2   0x07bd7ed0 0x07bdbed0 GLOBAL FUNC   16       imp.__stack_chk_fail
3   0x07bd7ee0 0x07bdbee0 GLOBAL FUNC   16       imp.acosf
4   0x07bd7f00 0x07bdbf00 GLOBAL FUNC   16       imp.powf
5   0x07bd7f20 0x07bdbf20 GLOBAL FUNC   16       imp.pthread_getspecific
6   0x07bd7f30 0x07bdbf30 GLOBAL FUNC   16       imp.pthread_setspecific
7   0x07bd7ef0 0x07bdbef0 GLOBAL FUNC   16       imp.sincosf
8   0x07bd7fe0 0x07bdbfe0 GLOBAL FUNC   16       imp.atan2f
9   0x07bd7f60 0x07bdbf60 GLOBAL FUNC   16       imp.free
10  0x07bd7f40 0x07bdbf40 GLOBAL FUNC   16       imp.getpagesize
11  0x07bd7f50 0x07bdbf50 GLOBAL FUNC   16       imp.malloc
12  0x07bd7f70 0x07bdbf70 GLOBAL FUNC   16       imp.realloc
13  0x07bd82c0 0x07bdc2c0 GLOBAL FUNC   16       imp.fread
14  0x07bd7f80 0x07bdbf80 GLOBAL FUNC   16       imp.pow
15  0x07bd8a80 0x07bdca80 GLOBAL FUNC   16       imp.acos
16  0x07bd8ae0 0x07bdcae0 GLOBAL FUNC   16       imp.sinf
17  0x07bd7f90 0x07bdbf90 GLOBAL FUNC   16       imp.longjmp
18  0x07bd7fa0 0x07bdbfa0 GLOBAL FUNC   16       imp.setjmp
19  0x07bd7fb0 0x07bdbfb0 GLOBAL FUNC   16       imp.sprintf
20  0x07bd81d0 0x07bdc1d0 GLOBAL FUNC   16       imp.cosf
21  0x07bd8ab0 0x07bdcab0 GLOBAL FUNC   16       imp.expf
22  0x07bd7fc0 0x07bdbfc0 GLOBAL FUNC   16       imp.logf
23  0x07bd7fd0 0x07bdbfd0 GLOBAL FUNC   16       imp.ldexp
24  0x07bd7ff0 0x07bdbff0 GLOBAL FUNC   16       imp.tanf
25  0x07bd8680 0x07bdc680 GLOBAL FUNC   16       imp.atanf
26  0x07bd81e0 0x07bdc1e0 GLOBAL FUNC   16       imp.fmod
27  0x07bd8000 0x07bdc000 GLOBAL FUNC   16       imp.qsort
28  0x07bd80f0 0x07bdc0f0 GLOBAL FUNC   16       imp.clock_gettime
29  0x07bd80e0 0x07bdc0e0 GLOBAL FUNC   16       imp.pthread_cond_broadcast
30  0x07bd8020 0x07bdc020 GLOBAL FUNC   16       imp.pthread_cond_destroy
31  0x07bd80c0 0x07bdc0c0 GLOBAL FUNC   16       imp.pthread_cond_init
32  0x07bd8100 0x07bdc100 GLOBAL FUNC   16       imp.pthread_cond_timedwait
33  0x07bd8040 0x07bdc040 GLOBAL FUNC   16       imp.pthread_cond_wait
34  0x07bd80d0 0x07bdc0d0 GLOBAL FUNC   16       imp.pthread_condattr_destroy
35  0x07bd80a0 0x07bdc0a0 GLOBAL FUNC   16       imp.pthread_condattr_init
36  0x07bd80b0 0x07bdc0b0 GLOBAL FUNC   16       imp.pthread_condattr_setclock
37  0x07bd8010 0x07bdc010 GLOBAL FUNC   16       imp.pthread_mutex_destroy
38  0x07bd8080 0x07bdc080 GLOBAL FUNC   16       imp.pthread_mutex_init
39  0x07bd8030 0x07bdc030 GLOBAL FUNC   16       imp.pthread_mutex_lock
40  0x07bd8050 0x07bdc050 GLOBAL FUNC   16       imp.pthread_mutex_unlock
41  0x07bd8090 0x07bdc090 GLOBAL FUNC   16       imp.pthread_mutexattr_destroy
42  0x07bd8060 0x07bdc060 GLOBAL FUNC   16       imp.pthread_mutexattr_init
43  0x07bd8070 0x07bdc070 GLOBAL FUNC   16       imp.pthread_mutexattr_settype
44  0x07bd8130 0x07bdc130 GLOBAL FUNC   16       imp.dlclose
45  0x07bd8120 0x07bdc120 GLOBAL FUNC   16       imp.dlerror
46  0x07bd8110 0x07bdc110 GLOBAL FUNC   16       imp.dlopen
47  0x07bd8140 0x07bdc140 GLOBAL FUNC   16       imp.dlsym
48  0x07bd8190 0x07bdc190 GLOBAL FUNC   16       imp.__errno
49  0x07bd86e0 0x07bdc6e0 GLOBAL FUNC   16       imp.freeaddrinfo
50  0x07bd86d0 0x07bdc6d0 GLOBAL FUNC   16       imp.getaddrinfo
51  0x07bd8e10 0x07bdce10 GLOBAL FUNC   16       imp.getnameinfo
52  0x07bd8cd0 0x07bdccd0 GLOBAL FUNC   16       imp.select
53  0x07bd82a0 0x07bdc2a0 GLOBAL FUNC   16       imp.strerror
54  0x07bd8150 0x07bdc150 WEAK   NOTYPE 16       imp._ZTH15gDeferredAction
55  0x07bd8160 0x07bdc160 GLOBAL FUNC   16       imp.fmodf
56  0x07bd8770 0x07bdc770 GLOBAL FUNC   16       imp.exit
57  0x07bd8170 0x07bdc170 GLOBAL FUNC   16       imp.gettimeofday
58  0x07bd8740 0x07bdc740 GLOBAL FUNC   16       imp.gmtime
59  0x07bd8180 0x07bdc180 GLOBAL FUNC   16       imp.getpwuid
60  0x07bd81b0 0x07bdc1b0 GLOBAL FUNC   16       imp.realpath
61  0x07bd81a0 0x07bdc1a0 GLOBAL FUNC   16       imp.symlink
62  0x07bd81c0 0x07bdc1c0 GLOBAL FUNC   16       imp.utime
63  0x07bd81f0 0x07bdc1f0 GLOBAL FUNC   16       imp.modf
64  0x07bd8210 0x07bdc210 GLOBAL FUNC   16       imp.ANativeWindow_getHeight
65  0x07bd8200 0x07bdc200 GLOBAL FUNC   16       imp.ANativeWindow_getWidth
66  0x07bd8260 0x07bdc260 GLOBAL FUNC   16       imp.ANativeWindow_setBuffersGeometry
67  0x07bd8240 0x07bdc240 GLOBAL FUNC   16       imp.eglGetConfigAttrib
68  0x07bd8250 0x07bdc250 GLOBAL FUNC   16       imp.eglGetError
69  0x07bd8220 0x07bdc220 GLOBAL FUNC   16       imp.eglQuerySurface
70  0x07bd8230 0x07bdc230 GLOBAL FUNC   16       imp.eglSurfaceAttrib
71  0x07bd8270 0x07bdc270 GLOBAL FUNC   16       imp.eglSwapBuffers
72  0x07bd82b0 0x07bdc2b0 GLOBAL FUNC   16       imp.inflate
73  0x07bd8290 0x07bdc290 GLOBAL FUNC   16       imp.inflateEnd
74  0x07bd8280 0x07bdc280 GLOBAL FUNC   16       imp.inflateInit2_
75  0x07bd8390 0x07bdc390 GLOBAL FUNC   16       imp.dladdr
76  0x07bd8340 0x07bdc340 GLOBAL FUNC   16       imp.getpriority
77  0x07bd8300 0x07bdc300 GLOBAL FUNC   16       imp.pthread_attr_init
78  0x07bd8310 0x07bdc310 GLOBAL FUNC   16       imp.pthread_attr_setstacksize
79  0x07bd8350 0x07bdc350 GLOBAL FUNC   16       imp.pthread_cond_signal
80  0x07bd8320 0x07bdc320 GLOBAL FUNC   16       imp.pthread_create
81  0x07bd8360 0x07bdc360 GLOBAL FUNC   16       imp.pthread_exit
82  0x07bd8370 0x07bdc370 GLOBAL FUNC   16       imp.pthread_join
83  0x07bd8380 0x07bdc380 GLOBAL FUNC   16       imp.pthread_self
84  0x07bd82e0 0x07bdc2e0 GLOBAL FUNC   16       imp.sigaction
85  0x07bd82d0 0x07bdc2d0 GLOBAL FUNC   16       imp.sigemptyset
86  0x07bd82f0 0x07bdc2f0 GLOBAL FUNC   16       imp.strcat
87  0x07bd8330 0x07bdc330 GLOBAL FUNC   16       imp.syscall
88  0x07bd83b0 0x07bdc3b0 GLOBAL FUNC   16       imp.ANativeWindow_acquire
89  0x07bd83c0 0x07bdc3c0 GLOBAL FUNC   16       imp.ANativeWindow_fromSurface
90  0x07bd83a0 0x07bdc3a0 GLOBAL FUNC   16       imp.ANativeWindow_release
91  0x07bd83d0 0x07bdc3d0 GLOBAL FUNC   16       imp.calloc
92  0x07bd8430 0x07bdc430 WEAK   NOTYPE 16       imp.AHardwareBuffer_describe
93  0x07bd8400 0x07bdc400 WEAK   NOTYPE 16       imp.AHardwareBuffer_release
94  0x07bd8420 0x07bdc420 WEAK   NOTYPE 16       imp.AImageReader_setBufferRemovedListener
95  0x07bd8410 0x07bdc410 WEAK   NOTYPE 16       imp.AImage_delete
96  0x07bd8460 0x07bdc460 WEAK   NOTYPE 16       imp.AImage_deleteAsync
97  0x07bd83f0 0x07bdc3f0 WEAK   NOTYPE 16       imp.AImage_getHardwareBuffer
98  0x07bd8450 0x07bdc450 WEAK   NOTYPE 16       imp.AImage_getWidth
99  0x07bd8440 0x07bdc440 GLOBAL FUNC   16       imp.__system_property_get
100 0x07bd83e0 0x07bdc3e0 GLOBAL FUNC   16       imp.eglMakeCurrent
101 0x07bd8470 0x07bdc470 GLOBAL FUNC   16       imp.pthread_once
102 0x07bd88d0 0x07bdc8d0 WEAK   NOTYPE 16       imp.ANativeWindow_toSurface
103 0x07bd8840 0x07bdc840 WEAK   NOTYPE 16       imp.AImageReader_acquireLatestImage
104 0x07bd8860 0x07bdc860 WEAK   NOTYPE 16       imp.AImageReader_delete
105 0x07bd88c0 0x07bdc8c0 WEAK   NOTYPE 16       imp.AImageReader_getWindow
106 0x07bd88b0 0x07bdc8b0 WEAK   NOTYPE 16       imp.AImageReader_newWithUsage
107 0x07bd8850 0x07bdc850 WEAK   NOTYPE 16       imp.AImageReader_setImageListener
108 0x07bd84a0 0x07bdc4a0 GLOBAL FUNC   16       imp.ALooper_forThread
109 0x07bd84b0 0x07bdc4b0 GLOBAL FUNC   16       imp.ALooper_prepare
110 0x07bd8530 0x07bdc530 GLOBAL FUNC   16       imp.ASensorEventQueue_disableSensor
111 0x07bd8510 0x07bdc510 GLOBAL FUNC   16       imp.ASensorEventQueue_enableSensor
112 0x07bd84f0 0x07bdc4f0 GLOBAL FUNC   16       imp.ASensorEventQueue_getEvents
113 0x07bd84e0 0x07bdc4e0 GLOBAL FUNC   16       imp.ASensorEventQueue_hasEvents
114 0x07bd8590 0x07bdc590 GLOBAL FUNC   16       imp.ASensorEventQueue_setEventRate
115 0x07bd84c0 0x07bdc4c0 GLOBAL FUNC   16       imp.ASensorManager_createEventQueue
116 0x07bd8520 0x07bdc520 GLOBAL FUNC   16       imp.ASensorManager_destroyEventQueue
117 0x07bd8500 0x07bdc500 GLOBAL FUNC   16       imp.ASensorManager_getDefaultSensor
118 0x07bd8490 0x07bdc490 GLOBAL FUNC   16       imp.ASensorManager_getInstance
119 0x07bd84d0 0x07bdc4d0 GLOBAL FUNC   16       imp.ASensorManager_getSensorList
120 0x07bd8560 0x07bdc560 GLOBAL FUNC   16       imp.ASensor_getMinDelay
121 0x07bd8570 0x07bdc570 GLOBAL FUNC   16       imp.ASensor_getName
122 0x07bd8550 0x07bdc550 GLOBAL FUNC   16       imp.ASensor_getResolution
123 0x07bd8540 0x07bdc540 GLOBAL FUNC   16       imp.ASensor_getType
124 0x07bd8580 0x07bdc580 GLOBAL FUNC   16       imp.ASensor_getVendor
125 0x07bd85a0 0x07bdc5a0 GLOBAL FUNC   16       imp.eglChooseConfig
126 0x07bd85b0 0x07bdc5b0 GLOBAL FUNC   16       imp.eglCreateContext
127 0x07bd8600 0x07bdc600 GLOBAL FUNC   16       imp.eglCreatePbufferSurface
128 0x07bd8610 0x07bdc610 GLOBAL FUNC   16       imp.eglCreateWindowSurface
129 0x07bd85e0 0x07bdc5e0 GLOBAL FUNC   16       imp.eglDestroyContext
130 0x07bd8640 0x07bdc640 GLOBAL FUNC   16       imp.eglDestroySurface
131 0x07bd8660 0x07bdc660 GLOBAL FUNC   16       imp.eglGetCurrentContext
132 0x07bd8650 0x07bdc650 GLOBAL FUNC   16       imp.eglGetCurrentSurface
133 0x07bd85c0 0x07bdc5c0 GLOBAL FUNC   16       imp.eglGetDisplay
134 0x07bd85d0 0x07bdc5d0 GLOBAL FUNC   16       imp.eglInitialize
135 0x07bd85f0 0x07bdc5f0 GLOBAL FUNC   16       imp.eglQueryString
136 0x07bd8630 0x07bdc630 GLOBAL FUNC   16       imp.eglSwapInterval
137 0x07bd8620 0x07bdc620 GLOBAL FUNC   16       imp.eglTerminate
138 0x07bd8670 0x07bdc670 GLOBAL FUNC   16       imp.modff
139 0x07bd8690 0x07bdc690 GLOBAL FUNC   16       imp.log10f
140 0x07bd86a0 0x07bdc6a0 GLOBAL FUNC   16       imp.memrchr
141 0x07bd86b0 0x07bdc6b0 GLOBAL FUNC   16       imp.gmtime_r
142 0x07bd86c0 0x07bdc6c0 GLOBAL FUNC   16       imp.poll
143 0x07bd86f0 0x07bdc6f0 GLOBAL FUNC   16       imp.pthread_detach
144 0x07bd8700 0x07bdc700 GLOBAL FUNC   16       imp.strerror_r
145 0x07bd8710 0x07bdc710 GLOBAL FUNC   16       imp.getpwuid_r
146 0x07bd8720 0x07bdc720 GLOBAL FUNC   16       imp.strftime
147 0x07bd8760 0x07bdc760 GLOBAL FUNC   16       imp.difftime
148 0x07bd8730 0x07bdc730 GLOBAL FUNC   16       imp.localtime
149 0x07bd8750 0x07bdc750 GLOBAL FUNC   16       imp.mktime
150 0x07bd8af0 0x07bdcaf0 GLOBAL FUNC   16       imp.asinf
151 0x07bd8d80 0x07bdcd80 GLOBAL FUNC   16       imp.atan2
152 0x07bd8d40 0x07bdcd40 GLOBAL FUNC   16       imp.tan
153 0x07bd8780 0x07bdc780 GLOBAL FUNC   16       imp.log2f
154 0x07bd8aa0 0x07bdcaa0 GLOBAL FUNC   16       imp.exp2f
155 0x07bd8a70 0x07bdca70 WEAK   NOTYPE 16       imp.AImage_getTimestamp
156 ---------- ---------- GLOBAL OBJ    16       imp.AMEDIAFORMAT_KEY_CHANNEL_COUNT
157 ---------- ---------- GLOBAL OBJ    16       imp.AMEDIAFORMAT_KEY_COLOR_FORMAT
158 ---------- ---------- WEAK   NOTYPE 16       imp.AMEDIAFORMAT_KEY_COLOR_RANGE
159 ---------- ---------- WEAK   NOTYPE 16       imp.AMEDIAFORMAT_KEY_COLOR_STANDARD
160 ---------- ---------- GLOBAL OBJ    16       imp.AMEDIAFORMAT_KEY_DURATION
161 ---------- ---------- WEAK   NOTYPE 16       imp.AMEDIAFORMAT_KEY_ENCODER_DELAY
162 ---------- ---------- GLOBAL OBJ    16       imp.AMEDIAFORMAT_KEY_FRAME_RATE
163 ---------- ---------- GLOBAL OBJ    16       imp.AMEDIAFORMAT_KEY_HEIGHT
164 ---------- ---------- GLOBAL OBJ    16       imp.AMEDIAFORMAT_KEY_LANGUAGE
165 ---------- ---------- GLOBAL OBJ    16       imp.AMEDIAFORMAT_KEY_MIME
166 ---------- ---------- WEAK   NOTYPE 16       imp.AMEDIAFORMAT_KEY_ROTATION
167 ---------- ---------- GLOBAL OBJ    16       imp.AMEDIAFORMAT_KEY_SAMPLE_RATE
168 ---------- ---------- WEAK   NOTYPE 16       imp.AMEDIAFORMAT_KEY_SLICE_HEIGHT
169 ---------- ---------- GLOBAL OBJ    16       imp.AMEDIAFORMAT_KEY_STRIDE
170 ---------- ---------- GLOBAL OBJ    16       imp.AMEDIAFORMAT_KEY_WIDTH
171 0x07bd8890 0x07bdc890 GLOBAL FUNC   16       imp.AMediaCodec_configure
172 0x07bd8880 0x07bdc880 GLOBAL FUNC   16       imp.AMediaCodec_createDecoderByType
173 0x07bd8830 0x07bdc830 GLOBAL FUNC   16       imp.AMediaCodec_delete
174 0x07bd87e0 0x07bdc7e0 GLOBAL FUNC   16       imp.AMediaCodec_dequeueInputBuffer
175 0x07bd8900 0x07bdc900 GLOBAL FUNC   16       imp.AMediaCodec_dequeueOutputBuffer
176 0x07bd87f0 0x07bdc7f0 GLOBAL FUNC   16       imp.AMediaCodec_flush
177 0x07bd8940 0x07bdc940 GLOBAL FUNC   16       imp.AMediaCodec_getInputBuffer
178 0x07bd8920 0x07bdc920 GLOBAL FUNC   16       imp.AMediaCodec_getOutputBuffer
179 0x07bd8910 0x07bdc910 GLOBAL FUNC   16       imp.AMediaCodec_getOutputFormat
180 0x07bd8950 0x07bdc950 GLOBAL FUNC   16       imp.AMediaCodec_queueInputBuffer
181 0x07bd8930 0x07bdc930 GLOBAL FUNC   16       imp.AMediaCodec_releaseOutputBuffer
182 0x07bd8a30 0x07bdca30 WEAK   NOTYPE 16       imp.AMediaCodec_setOutputSurface
183 0x07bd88a0 0x07bdc8a0 GLOBAL FUNC   16       imp.AMediaCodec_start
184 0x07bd8800 0x07bdc800 GLOBAL FUNC   16       imp.AMediaCodec_stop
185 0x07bd8980 0x07bdc980 WEAK   NOTYPE 16       imp.AMediaDataSource_delete
186 0x07bd89a0 0x07bdc9a0 WEAK   NOTYPE 16       imp.AMediaDataSource_new
187 0x07bd8a10 0x07bdca10 WEAK   NOTYPE 16       imp.AMediaDataSource_setClose
188 0x07bd8a00 0x07bdca00 WEAK   NOTYPE 16       imp.AMediaDataSource_setGetSize
189 0x07bd89f0 0x07bdc9f0 WEAK   NOTYPE 16       imp.AMediaDataSource_setReadAt
190 0x07bd89e0 0x07bdc9e0 WEAK   NOTYPE 16       imp.AMediaDataSource_setUserdata
191 0x07bd88f0 0x07bdc8f0 GLOBAL FUNC   16       imp.AMediaExtractor_advance
192 0x07bd87d0 0x07bdc7d0 GLOBAL FUNC   16       imp.AMediaExtractor_delete
193 0x07bd8970 0x07bdc970 GLOBAL FUNC   16       imp.AMediaExtractor_getSampleTime
194 0x07bd88e0 0x07bdc8e0 GLOBAL FUNC   16       imp.AMediaExtractor_getSampleTrackIndex
195 0x07bd8a50 0x07bdca50 GLOBAL FUNC   16       imp.AMediaExtractor_getTrackCount
196 0x07bd8810 0x07bdc810 GLOBAL FUNC   16       imp.AMediaExtractor_getTrackFormat
197 0x07bd8990 0x07bdc990 GLOBAL FUNC   16       imp.AMediaExtractor_new
198 0x07bd8960 0x07bdc960 GLOBAL FUNC   16       imp.AMediaExtractor_readSampleData
199 0x07bd8790 0x07bdc790 GLOBAL FUNC   16       imp.AMediaExtractor_seekTo
200 0x07bd8870 0x07bdc870 GLOBAL FUNC   16       imp.AMediaExtractor_selectTrack
201 0x07bd89c0 0x07bdc9c0 GLOBAL FUNC   16       imp.AMediaExtractor_setDataSource
202 0x07bd8a20 0x07bdca20 WEAK   NOTYPE 16       imp.AMediaExtractor_setDataSourceCustom
203 0x07bd89b0 0x07bdc9b0 GLOBAL FUNC   16       imp.AMediaExtractor_setDataSourceFd
204 0x07bd87c0 0x07bdc7c0 GLOBAL FUNC   16       imp.AMediaFormat_delete
205 0x07bd8a40 0x07bdca40 GLOBAL FUNC   16       imp.AMediaFormat_getFloat
206 0x07bd87b0 0x07bdc7b0 GLOBAL FUNC   16       imp.AMediaFormat_getInt32
207 0x07bd87a0 0x07bdc7a0 GLOBAL FUNC   16       imp.AMediaFormat_getInt64
208 0x07bd8820 0x07bdc820 GLOBAL FUNC   16       imp.AMediaFormat_getString
209 0x07bd8a60 0x07bdca60 GLOBAL FUNC   16       imp.AMediaFormat_setInt32
210 0x07bd89d0 0x07bdc9d0 GLOBAL FUNC   16       imp.strcasestr
211 0x07bd8a90 0x07bdca90 GLOBAL FUNC   16       imp.cos
212 0x07bd8ad0 0x07bdcad0 GLOBAL FUNC   16       imp.cbrtf
213 0x07bd8ac0 0x07bdcac0 GLOBAL FUNC   16       imp.exp
214 0x07bd8b00 0x07bdcb00 GLOBAL FUNC   16       imp.eglGetProcAddress
215 0x07bd8d60 0x07bdcd60 GLOBAL FUNC   16       imp.asin
216 0x07bd8d70 0x07bdcd70 GLOBAL FUNC   16       imp.atan
217 0x07bd8cf0 0x07bdccf0 GLOBAL FUNC   16       imp.log
218 0x07bd8b10 0x07bdcb10 GLOBAL FUNC   16       imp.pthread_key_create
219 0x07bd8c20 0x07bdcc20 GLOBAL FUNC   16       imp.pthread_key_delete
220 0x07bd8ea0 0x07bdcea0 GLOBAL FUNC   16       imp.pthread_kill
221 0x07bd8b90 0x07bdcb90 GLOBAL FUNC   16       imp.pthread_mutex_trylock
222 0x07bd8ca0 0x07bdcca0 GLOBAL FUNC   16       imp.sem_destroy
223 0x07bd8c90 0x07bdcc90 GLOBAL FUNC   16       imp.sem_init
224 0x07bd8cc0 0x07bdccc0 GLOBAL FUNC   16       imp.sem_post
225 0x07bd8eb0 0x07bdceb0 GLOBAL FUNC   16       imp.sem_timedwait
226 0x07bd8cb0 0x07bdccb0 GLOBAL FUNC   16       imp.sem_wait
227 0x07bd8d00 0x07bdcd00 GLOBAL FUNC   16       imp.sin
228 0x07bd8c60 0x07bdcc60 GLOBAL FUNC   16       imp.usleep
229 0x07bd8b20 0x07bdcb20 GLOBAL FUNC   16       imp.pthread_rwlock_init
230 0x07bd8b30 0x07bdcb30 GLOBAL FUNC   16       imp.pthread_rwlock_rdlock
231 0x07bd8b40 0x07bdcb40 GLOBAL FUNC   16       imp.pthread_rwlock_unlock
232 0x07bd8b50 0x07bdcb50 GLOBAL FUNC   16       imp.pthread_rwlock_wrlock
233 0x07bd8b60 0x07bdcb60 GLOBAL FUNC   16       imp.__system_property_find
234 0x07bd8b70 0x07bdcb70 GLOBAL FUNC   16       imp.__system_property_read
235 0x07bd8da0 0x07bdcda0 GLOBAL FUNC   16       imp.readlink
236 0x07bd8b80 0x07bdcb80 GLOBAL FUNC   16       imp.localtime_r
237 0x07bd8ba0 0x07bdcba0 GLOBAL FUNC   16       imp.ALooper_acquire
238 0x07bd8be0 0x07bdcbe0 GLOBAL FUNC   16       imp.ALooper_pollOnce
239 0x07bd8bc0 0x07bdcbc0 GLOBAL FUNC   16       imp.ALooper_release
240 0x07bd8bb0 0x07bdcbb0 GLOBAL FUNC   16       imp.ALooper_wake
241 0x07bd8bd0 0x07bdcbd0 GLOBAL FUNC   16       imp.pthread_setname_np
242 0x07bd8bf0 0x07bdcbf0 GLOBAL FUNC   16       imp.sched_getaffinity
243 0x07bd8c00 0x07bdcc00 GLOBAL FUNC   16       imp.lldiv
244 0x07bd8c10 0x07bdcc10 GLOBAL FUNC   16       imp.getauxval
245 0x07bd8d20 0x07bdcd20 GLOBAL FUNC   16       imp.memalign
246 0x07bd8c30 0x07bdcc30 GLOBAL FUNC   16       imp.posix_memalign
247 0x07bd8c80 0x07bdcc80 GLOBAL FUNC   16       imp.pthread_attr_destroy
248 0x07bd8c40 0x07bdcc40 GLOBAL FUNC   16       imp.sqrtf
249 0x07bd8c50 0x07bdcc50 GLOBAL FUNC   16       imp.ldexpf
250 0x07bd8c70 0x07bdcc70 GLOBAL FUNC   16       imp.pthread_attr_setdetachstate
251 0x07bd8ce0 0x07bdcce0 GLOBAL FUNC   16       imp.gethostbyname
252 0x07bd8d10 0x07bdcd10 GLOBAL FUNC   16       imp.gethostbyaddr
253 0x07bd8d30 0x07bdcd30 GLOBAL FUNC   16       imp.pthread_equal
254 0x07bd8d90 0x07bdcd90 GLOBAL FUNC   16       imp.bsearch
255 0x07bd8d50 0x07bdcd50 GLOBAL FUNC   16       imp.log10
256 0x07bd8dc0 0x07bdcdc0 GLOBAL FUNC   16       imp.lrand48
257 0x07bd8db0 0x07bdcdb0 GLOBAL FUNC   16       imp.srand48
258 0x07bd8dd0 0x07bdcdd0 GLOBAL FUNC   16       imp.div
259 ---------- ---------- GLOBAL OBJ    16       imp.environ
260 0x07bd8de0 0x07bdcde0 GLOBAL FUNC   16       imp.hypot
261 0x07bd8df0 0x07bdcdf0 GLOBAL FUNC   16       imp.logb
262 0x07bd8e00 0x07bdce00 GLOBAL FUNC   16       imp.scalbn
263 0x07bd8f10 0x07bdcf10 GLOBAL FUNC   16       imp.pclose
264 0x07bd8f00 0x07bdcf00 GLOBAL FUNC   16       imp.popen
265 0x07bd8e50 0x07bdce50 GLOBAL FUNC   16       imp.pthread_atfork
266 0x07bd8e40 0x07bdce40 GLOBAL FUNC   16       imp.pthread_attr_getstack
267 0x07bd8e30 0x07bdce30 GLOBAL FUNC   16       imp.pthread_getattr_np
268 0x07bd8e80 0x07bdce80 GLOBAL FUNC   16       imp.pthread_sigmask
269 0x07bd8ed0 0x07bdced0 GLOBAL FUNC   16       imp.sem_getvalue
270 0x07bd8e70 0x07bdce70 GLOBAL FUNC   16       imp.sigaddset
271 0x07bd8e60 0x07bdce60 GLOBAL FUNC   16       imp.sigdelset
272 0x07bd8ec0 0x07bdcec0 GLOBAL FUNC   16       imp.sigfillset
273 0x07bd8e20 0x07bdce20 GLOBAL FUNC   16       imp.signal
274 0x07bd8e90 0x07bdce90 GLOBAL FUNC   16       imp.sigsuspend
275 0x07bd8f70 0x07bdcf70 GLOBAL FUNC   16       imp.strtold
276 0x07bd8ee0 0x07bdcee0 GLOBAL FUNC   16       imp.wcslen
277 0x07bd8ef0 0x07bdcef0 GLOBAL FUNC   16       imp.wmemset
278 0x07bd8f20 0x07bdcf20 GLOBAL FUNC   16       imp.pthread_gettid_np
279 0x07bd8f30 0x07bdcf30 GLOBAL FUNC   16       imp.arc4random
280 0x07bd8f40 0x07bdcf40 GLOBAL FUNC   16       imp.random
281 0x07bd8f50 0x07bdcf50 GLOBAL FUNC   16       imp.sleep
282 0x07bd8f60 0x07bdcf60 GLOBAL FUNC   16       imp.nextafter
283 ---------- ---------- GLOBAL OBJ    16       imp.__stack_chk_guard
284 0x07bd8f90 0x07bdcf90 GLOBAL FUNC   16       imp.__system_property_area_serial
285 0x07bd8f80 0x07bdcf80 GLOBAL FUNC   16       imp.__system_property_serial
286 0x07bd8fa0 0x07bdcfa0 GLOBAL FUNC   16       imp.tcgetattr
287 ---------- ---------- GLOBAL OBJ    16       imp.__progname
288 0x07bd8fb0 0x07bdcfb0 GLOBAL FUNC   16       imp.dl_iterate_phdr


// ===== IMPORTS =====
// ============================
nth vaddr      bind   type   lib name
―――――――――――――――――――――――――――――――――――――
1   0x07bdbf10 GLOBAL FUNC       __cxa_atexit
2   0x07bdbed0 GLOBAL FUNC       __stack_chk_fail
3   0x07bdbee0 GLOBAL FUNC       acosf
4   0x07bdbf00 GLOBAL FUNC       powf
5   0x07bdbf20 GLOBAL FUNC       pthread_getspecific
6   0x07bdbf30 GLOBAL FUNC       pthread_setspecific
7   0x07bdbef0 GLOBAL FUNC       sincosf
8   0x07bdbfe0 GLOBAL FUNC       atan2f
9   0x07bdbf60 GLOBAL FUNC       free
10  0x07bdbf40 GLOBAL FUNC       getpagesize
11  0x07bdbf50 GLOBAL FUNC       malloc
12  0x07bdbf70 GLOBAL FUNC       realloc
13  0x07bdc2c0 GLOBAL FUNC       fread
14  0x07bdbf80 GLOBAL FUNC       pow
15  0x07bdca80 GLOBAL FUNC       acos
16  0x07bdcae0 GLOBAL FUNC       sinf
17  0x07bdbf90 GLOBAL FUNC       longjmp
18  0x07bdbfa0 GLOBAL FUNC       setjmp
19  0x07bdbfb0 GLOBAL FUNC       sprintf
20  0x07bdc1d0 GLOBAL FUNC       cosf
21  0x07bdcab0 GLOBAL FUNC       expf
22  0x07bdbfc0 GLOBAL FUNC       logf
23  0x07bdbfd0 GLOBAL FUNC       ldexp
24  0x07bdbff0 GLOBAL FUNC       tanf
25  0x07bdc680 GLOBAL FUNC       atanf
26  0x07bdc1e0 GLOBAL FUNC       fmod
27  0x07bdc000 GLOBAL FUNC       qsort
28  0x07bdc0f0 GLOBAL FUNC       clock_gettime
29  0x07bdc0e0 GLOBAL FUNC       pthread_cond_broadcast
30  0x07bdc020 GLOBAL FUNC       pthread_cond_destroy
31  0x07bdc0c0 GLOBAL FUNC       pthread_cond_init
32  0x07bdc100 GLOBAL FUNC       pthread_cond_timedwait
33  0x07bdc040 GLOBAL FUNC       pthread_cond_wait
34  0x07bdc0d0 GLOBAL FUNC       pthread_condattr_destroy
35  0x07bdc0a0 GLOBAL FUNC       pthread_condattr_init
36  0x07bdc0b0 GLOBAL FUNC       pthread_condattr_setclock
37  0x07bdc010 GLOBAL FUNC       pthread_mutex_destroy
38  0x07bdc080 GLOBAL FUNC       pthread_mutex_init
39  0x07bdc030 GLOBAL FUNC       pthread_mutex_lock
40  0x07bdc050 GLOBAL FUNC       pthread_mutex_unlock
41  0x07bdc090 GLOBAL FUNC       pthread_mutexattr_destroy
42  0x07bdc060 GLOBAL FUNC       pthread_mutexattr_init
43  0x07bdc070 GLOBAL FUNC       pthread_mutexattr_settype
44  0x07bdc130 GLOBAL FUNC       dlclose
45  0x07bdc120 GLOBAL FUNC       dlerror
46  0x07bdc110 GLOBAL FUNC       dlopen
47  0x07bdc140 GLOBAL FUNC       dlsym
48  0x07bdc190 GLOBAL FUNC       __errno
49  0x07bdc6e0 GLOBAL FUNC       freeaddrinfo
50  0x07bdc6d0 GLOBAL FUNC       getaddrinfo
51  0x07bdce10 GLOBAL FUNC       getnameinfo
52  0x07bdccd0 GLOBAL FUNC       select
53  0x07bdc2a0 GLOBAL FUNC       strerror
54  0x07bdc150 WEAK   NOTYPE     _ZTH15gDeferredAction
55  0x07bdc160 GLOBAL FUNC       fmodf
56  0x07bdc770 GLOBAL FUNC       exit
57  0x07bdc170 GLOBAL FUNC       gettimeofday
58  0x07bdc740 GLOBAL FUNC       gmtime
59  0x07bdc180 GLOBAL FUNC       getpwuid
60  0x07bdc1b0 GLOBAL FUNC       realpath
61  0x07bdc1a0 GLOBAL FUNC       symlink
62  0x07bdc1c0 GLOBAL FUNC       utime
63  0x07bdc1f0 GLOBAL FUNC       modf
64  0x07bdc210 GLOBAL FUNC       ANativeWindow_getHeight
65  0x07bdc200 GLOBAL FUNC       ANativeWindow_getWidth
66  0x07bdc260 GLOBAL FUNC       ANativeWindow_setBuffersGeometry
67  0x07bdc240 GLOBAL FUNC       eglGetConfigAttrib
68  0x07bdc250 GLOBAL FUNC       eglGetError
69  0x07bdc220 GLOBAL FUNC       eglQuerySurface
70  0x07bdc230 GLOBAL FUNC       eglSurfaceAttrib
71  0x07bdc270 GLOBAL FUNC       eglSwapBuffers
72  0x07bdc2b0 GLOBAL FUNC       inflate
73  0x07bdc290 GLOBAL FUNC       inflateEnd
74  0x07bdc280 GLOBAL FUNC       inflateInit2_
75  0x07bdc390 GLOBAL FUNC       dladdr
76  0x07bdc340 GLOBAL FUNC       getpriority
77  0x07bdc300 GLOBAL FUNC       pthread_attr_init
78  0x07bdc310 GLOBAL FUNC       pthread_attr_setstacksize
79  0x07bdc350 GLOBAL FUNC       pthread_cond_signal
80  0x07bdc320 GLOBAL FUNC       pthread_create
81  0x07bdc360 GLOBAL FUNC       pthread_exit
82  0x07bdc370 GLOBAL FUNC       pthread_join
83  0x07bdc380 GLOBAL FUNC       pthread_self
84  0x07bdc2e0 GLOBAL FUNC       sigaction
85  0x07bdc2d0 GLOBAL FUNC       sigemptyset
86  0x07bdc2f0 GLOBAL FUNC       strcat
87  0x07bdc330 GLOBAL FUNC       syscall
88  0x07bdc3b0 GLOBAL FUNC       ANativeWindow_acquire
89  0x07bdc3c0 GLOBAL FUNC       ANativeWindow_fromSurface
90  0x07bdc3a0 GLOBAL FUNC       ANativeWindow_release
91  0x07bdc3d0 GLOBAL FUNC       calloc
92  0x07bdc430 WEAK   NOTYPE     AHardwareBuffer_describe
93  0x07bdc400 WEAK   NOTYPE     AHardwareBuffer_release
94  0x07bdc420 WEAK   NOTYPE     AImageReader_setBufferRemovedListener
95  0x07bdc410 WEAK   NOTYPE     AImage_delete
96  0x07bdc460 WEAK   NOTYPE     AImage_deleteAsync
97  0x07bdc3f0 WEAK   NOTYPE     AImage_getHardwareBuffer
98  0x07bdc450 WEAK   NOTYPE     AImage_getWidth
99  0x07bdc440 GLOBAL FUNC       __system_property_get
100 0x07bdc3e0 GLOBAL FUNC       eglMakeCurrent
101 0x07bdc470 GLOBAL FUNC       pthread_once
102 0x07bdc8d0 WEAK   NOTYPE     ANativeWindow_toSurface
103 0x07bdc840 WEAK   NOTYPE     AImageReader_acquireLatestImage
104 0x07bdc860 WEAK   NOTYPE     AImageReader_delete
105 0x07bdc8c0 WEAK   NOTYPE     AImageReader_getWindow
106 0x07bdc8b0 WEAK   NOTYPE     AImageReader_newWithUsage
107 0x07bdc850 WEAK   NOTYPE     AImageReader_setImageListener
108 0x07bdc4a0 GLOBAL FUNC       ALooper_forThread
109 0x07bdc4b0 GLOBAL FUNC       ALooper_prepare
110 0x07bdc530 GLOBAL FUNC       ASensorEventQueue_disableSensor
111 0x07bdc510 GLOBAL FUNC       ASensorEventQueue_enableSensor
112 0x07bdc4f0 GLOBAL FUNC       ASensorEventQueue_getEvents
113 0x07bdc4e0 GLOBAL FUNC       ASensorEventQueue_hasEvents
114 0x07bdc590 GLOBAL FUNC       ASensorEventQueue_setEventRate
115 0x07bdc4c0 GLOBAL FUNC       ASensorManager_createEventQueue
116 0x07bdc520 GLOBAL FUNC       ASensorManager_destroyEventQueue
117 0x07bdc500 GLOBAL FUNC       ASensorManager_getDefaultSensor
118 0x07bdc490 GLOBAL FUNC       ASensorManager_getInstance
119 0x07bdc4d0 GLOBAL FUNC       ASensorManager_getSensorList
120 0x07bdc560 GLOBAL FUNC       ASensor_getMinDelay
121 0x07bdc570 GLOBAL FUNC       ASensor_getName
122 0x07bdc550 GLOBAL FUNC       ASensor_getResolution
123 0x07bdc540 GLOBAL FUNC       ASensor_getType
124 0x07bdc580 GLOBAL FUNC       ASensor_getVendor
125 0x07bdc5a0 GLOBAL FUNC       eglChooseConfig
126 0x07bdc5b0 GLOBAL FUNC       eglCreateContext
127 0x07bdc600 GLOBAL FUNC       eglCreatePbufferSurface
128 0x07bdc610 GLOBAL FUNC       eglCreateWindowSurface
129 0x07bdc5e0 GLOBAL FUNC       eglDestroyContext
130 0x07bdc640 GLOBAL FUNC       eglDestroySurface
131 0x07bdc660 GLOBAL FUNC       eglGetCurrentContext
132 0x07bdc650 GLOBAL FUNC       eglGetCurrentSurface
133 0x07bdc5c0 GLOBAL FUNC       eglGetDisplay
134 0x07bdc5d0 GLOBAL FUNC       eglInitialize
135 0x07bdc5f0 GLOBAL FUNC       eglQueryString
136 0x07bdc630 GLOBAL FUNC       eglSwapInterval
137 0x07bdc620 GLOBAL FUNC       eglTerminate
138 0x07bdc670 GLOBAL FUNC       modff
139 0x07bdc690 GLOBAL FUNC       log10f
140 0x07bdc6a0 GLOBAL FUNC       memrchr
141 0x07bdc6b0 GLOBAL FUNC       gmtime_r
142 0x07bdc6c0 GLOBAL FUNC       poll
143 0x07bdc6f0 GLOBAL FUNC       pthread_detach
144 0x07bdc700 GLOBAL FUNC       strerror_r
145 0x07bdc710 GLOBAL FUNC       getpwuid_r
146 0x07bdc720 GLOBAL FUNC       strftime
147 0x07bdc760 GLOBAL FUNC       difftime
148 0x07bdc730 GLOBAL FUNC       localtime
149 0x07bdc750 GLOBAL FUNC       mktime
150 0x07bdcaf0 GLOBAL FUNC       asinf
151 0x07bdcd80 GLOBAL FUNC       atan2
152 0x07bdcd40 GLOBAL FUNC       tan
153 0x07bdc780 GLOBAL FUNC       log2f
154 0x07bdcaa0 GLOBAL FUNC       exp2f
155 0x07bdca70 WEAK   NOTYPE     AImage_getTimestamp
156 ---------- GLOBAL OBJ        AMEDIAFORMAT_KEY_CHANNEL_COUNT
157 ---------- GLOBAL OBJ        AMEDIAFORMAT_KEY_COLOR_FORMAT
158 ---------- WEAK   NOTYPE     AMEDIAFORMAT_KEY_COLOR_RANGE
159 ---------- WEAK   NOTYPE     AMEDIAFORMAT_KEY_COLOR_STANDARD
160 ---------- GLOBAL OBJ        AMEDIAFORMAT_KEY_DURATION
161 ---------- WEAK   NOTYPE     AMEDIAFORMAT_KEY_ENCODER_DELAY
162 ---------- GLOBAL OBJ        AMEDIAFORMAT_KEY_FRAME_RATE
163 ---------- GLOBAL OBJ        AMEDIAFORMAT_KEY_HEIGHT
164 ---------- GLOBAL OBJ        AMEDIAFORMAT_KEY_LANGUAGE
165 ---------- GLOBAL OBJ        AMEDIAFORMAT_KEY_MIME
166 ---------- WEAK   NOTYPE     AMEDIAFORMAT_KEY_ROTATION
167 ---------- GLOBAL OBJ        AMEDIAFORMAT_KEY_SAMPLE_RATE
168 ---------- WEAK   NOTYPE     AMEDIAFORMAT_KEY_SLICE_HEIGHT
169 ---------- GLOBAL OBJ        AMEDIAFORMAT_KEY_STRIDE
170 ---------- GLOBAL OBJ        AMEDIAFORMAT_KEY_WIDTH
171 0x07bdc890 GLOBAL FUNC       AMediaCodec_configure
172 0x07bdc880 GLOBAL FUNC       AMediaCodec_createDecoderByType
173 0x07bdc830 GLOBAL FUNC       AMediaCodec_delete
174 0x07bdc7e0 GLOBAL FUNC       AMediaCodec_dequeueInputBuffer
175 0x07bdc900 GLOBAL FUNC       AMediaCodec_dequeueOutputBuffer
176 0x07bdc7f0 GLOBAL FUNC       AMediaCodec_flush
177 0x07bdc940 GLOBAL FUNC       AMediaCodec_getInputBuffer
178 0x07bdc920 GLOBAL FUNC       AMediaCodec_getOutputBuffer
179 0x07bdc910 GLOBAL FUNC       AMediaCodec_getOutputFormat
180 0x07bdc950 GLOBAL FUNC       AMediaCodec_queueInputBuffer
181 0x07bdc930 GLOBAL FUNC       AMediaCodec_releaseOutputBuffer
182 0x07bdca30 WEAK   NOTYPE     AMediaCodec_setOutputSurface
183 0x07bdc8a0 GLOBAL FUNC       AMediaCodec_start
184 0x07bdc800 GLOBAL FUNC       AMediaCodec_stop
185 0x07bdc980 WEAK   NOTYPE     AMediaDataSource_delete
186 0x07bdc9a0 WEAK   NOTYPE     AMediaDataSource_new
187 0x07bdca10 WEAK   NOTYPE     AMediaDataSource_setClose
188 0x07bdca00 WEAK   NOTYPE     AMediaDataSource_setGetSize
189 0x07bdc9f0 WEAK   NOTYPE     AMediaDataSource_setReadAt
190 0x07bdc9e0 WEAK   NOTYPE     AMediaDataSource_setUserdata
191 0x07bdc8f0 GLOBAL FUNC       AMediaExtractor_advance
192 0x07bdc7d0 GLOBAL FUNC       AMediaExtractor_delete
193 0x07bdc970 GLOBAL FUNC       AMediaExtractor_getSampleTime
194 0x07bdc8e0 GLOBAL FUNC       AMediaExtractor_getSampleTrackIndex
195 0x07bdca50 GLOBAL FUNC       AMediaExtractor_getTrackCount
196 0x07bdc810 GLOBAL FUNC       AMediaExtractor_getTrackFormat
197 0x07bdc990 GLOBAL FUNC       AMediaExtractor_new
198 0x07bdc960 GLOBAL FUNC       AMediaExtractor_readSampleData
199 0x07bdc790 GLOBAL FUNC       AMediaExtractor_seekTo
200 0x07bdc870 GLOBAL FUNC       AMediaExtractor_selectTrack
201 0x07bdc9c0 GLOBAL FUNC       AMediaExtractor_setDataSource
202 0x07bdca20 WEAK   NOTYPE     AMediaExtractor_setDataSourceCustom
203 0x07bdc9b0 GLOBAL FUNC       AMediaExtractor_setDataSourceFd
204 0x07bdc7c0 GLOBAL FUNC       AMediaFormat_delete
205 0x07bdca40 GLOBAL FUNC       AMediaFormat_getFloat
206 0x07bdc7b0 GLOBAL FUNC       AMediaFormat_getInt32
207 0x07bdc7a0 GLOBAL FUNC       AMediaFormat_getInt64
208 0x07bdc820 GLOBAL FUNC       AMediaFormat_getString
209 0x07bdca60 GLOBAL FUNC       AMediaFormat_setInt32
210 0x07bdc9d0 GLOBAL FUNC       strcasestr
211 0x07bdca90 GLOBAL FUNC       cos
212 0x07bdcad0 GLOBAL FUNC       cbrtf
213 0x07bdcac0 GLOBAL FUNC       exp
214 0x07bdcb00 GLOBAL FUNC       eglGetProcAddress
215 0x07bdcd60 GLOBAL FUNC       asin
216 0x07bdcd70 GLOBAL FUNC       atan
217 0x07bdccf0 GLOBAL FUNC       log
218 0x07bdcb10 GLOBAL FUNC       pthread_key_create
219 0x07bdcc20 GLOBAL FUNC       pthread_key_delete
220 0x07bdcea0 GLOBAL FUNC       pthread_kill
221 0x07bdcb90 GLOBAL FUNC       pthread_mutex_trylock
222 0x07bdcca0 GLOBAL FUNC       sem_destroy
223 0x07bdcc90 GLOBAL FUNC       sem_init
224 0x07bdccc0 GLOBAL FUNC       sem_post
225 0x07bdceb0 GLOBAL FUNC       sem_timedwait
226 0x07bdccb0 GLOBAL FUNC       sem_wait
227 0x07bdcd00 GLOBAL FUNC       sin
228 0x07bdcc60 GLOBAL FUNC       usleep
229 0x07bdcb20 GLOBAL FUNC       pthread_rwlock_init
230 0x07bdcb30 GLOBAL FUNC       pthread_rwlock_rdlock
231 0x07bdcb40 GLOBAL FUNC       pthread_rwlock_unlock
232 0x07bdcb50 GLOBAL FUNC       pthread_rwlock_wrlock
233 0x07bdcb60 GLOBAL FUNC       __system_property_find
234 0x07bdcb70 GLOBAL FUNC       __system_property_read
235 0x07bdcda0 GLOBAL FUNC       readlink
236 0x07bdcb80 GLOBAL FUNC       localtime_r
237 0x07bdcba0 GLOBAL FUNC       ALooper_acquire
238 0x07bdcbe0 GLOBAL FUNC       ALooper_pollOnce
239 0x07bdcbc0 GLOBAL FUNC       ALooper_release
240 0x07bdcbb0 GLOBAL FUNC       ALooper_wake
241 0x07bdcbd0 GLOBAL FUNC       pthread_setname_np
242 0x07bdcbf0 GLOBAL FUNC       sched_getaffinity
243 0x07bdcc00 GLOBAL FUNC       lldiv
244 0x07bdcc10 GLOBAL FUNC       getauxval
245 0x07bdcd20 GLOBAL FUNC       memalign
246 0x07bdcc30 GLOBAL FUNC       posix_memalign
247 0x07bdcc80 GLOBAL FUNC       pthread_attr_destroy
248 0x07bdcc40 GLOBAL FUNC       sqrtf
249 0x07bdcc50 GLOBAL FUNC       ldexpf
250 0x07bdcc70 GLOBAL FUNC       pthread_attr_setdetachstate
251 0x07bdcce0 GLOBAL FUNC       gethostbyname
252 0x07bdcd10 GLOBAL FUNC       gethostbyaddr
253 0x07bdcd30 GLOBAL FUNC       pthread_equal
254 0x07bdcd90 GLOBAL FUNC       bsearch
255 0x07bdcd50 GLOBAL FUNC       log10
256 0x07bdcdc0 GLOBAL FUNC       lrand48
257 0x07bdcdb0 GLOBAL FUNC       srand48
258 0x07bdcdd0 GLOBAL FUNC       div
259 ---------- GLOBAL OBJ        environ
260 0x07bdcde0 GLOBAL FUNC       hypot
261 0x07bdcdf0 GLOBAL FUNC       logb
262 0x07bdce00 GLOBAL FUNC       scalbn
263 0x07bdcf10 GLOBAL FUNC       pclose
264 0x07bdcf00 GLOBAL FUNC       popen
265 0x07bdce50 GLOBAL FUNC       pthread_atfork
266 0x07bdce40 GLOBAL FUNC       pthread_attr_getstack
267 0x07bdce30 GLOBAL FUNC       pthread_getattr_np
268 0x07bdce80 GLOBAL FUNC       pthread_sigmask
269 0x07bdced0 GLOBAL FUNC       sem_getvalue
270 0x07bdce70 GLOBAL FUNC       sigaddset
271 0x07bdce60 GLOBAL FUNC       sigdelset
272 0x07bdcec0 GLOBAL FUNC       sigfillset
273 0x07bdce20 GLOBAL FUNC       signal
274 0x07bdce90 GLOBAL FUNC       sigsuspend
275 0x07bdcf70 GLOBAL FUNC       strtold
276 0x07bdcee0 GLOBAL FUNC       wcslen
277 0x07bdcef0 GLOBAL FUNC       wmemset
278 0x07bdcf20 GLOBAL FUNC       pthread_gettid_np
279 0x07bdcf30 GLOBAL FUNC       arc4random
280 0x07bdcf40 GLOBAL FUNC       random
281 0x07bdcf50 GLOBAL FUNC       sleep
282 0x07bdcf60 GLOBAL FUNC       nextafter
283 ---------- GLOBAL OBJ        __stack_chk_guard
284 0x07bdcf90 GLOBAL FUNC       __system_property_area_serial
285 0x07bdcf80 GLOBAL FUNC       __system_property_serial
286 0x07bdcfa0 GLOBAL FUNC       tcgetattr
287 ---------- GLOBAL OBJ        __progname
288 0x07bdcfb0 GLOBAL FUNC       dl_iterate_phdr


// ===== EXPORTS =====
// ============================
nth paddr      vaddr      bind   type size lib name                     demangled
―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――
289 0x03c220ac 0x03c260ac GLOBAL FUNC 164      JNI_OnLoad
290 0x03c2242c 0x03c2642c GLOBAL FUNC 144      JNI_OnUnload
291 0x03c82ee4 0x03c86ee4 GLOBAL FUNC 204      UnitySendMessage
292 0x03bf85bc 0x03bfc5bc GLOBAL FUNC 12       UnitySwappy_version
293 0x03bf85c8 0x03bfc5c8 GLOBAL FUNC 52       UnitySwappy_injectTracer


// ===== FUNCTIONS =====
// ============================
Usage: rabin2 [-AcdeEghHiIjJlLMqrRsSUvVxzZ] [-@ at] [-a arch] [-b bits] [-B addr]
              [-C F:C:D] [-f str] [-m addr] [-n str] [-N m:M] [-P[-P] pdb]
              [-o str] [-O help] [-k query] [-D lang mangledsymbol] file


// ===== RELOCATIONS =====
// ============================
Usage: rabin2 [-AcdeEghHiIjJlLMqrRsSUvVxzZ] [-@ at] [-a arch] [-b bits] [-B addr]
              [-C F:C:D] [-f str] [-m addr] [-n str] [-N m:M] [-P[-P] pdb]
              [-o str] [-O help] [-k query] [-D lang mangledsymbol] file


// ===== DYNAMIC =====
// ============================


// ===== NEEDED LIBS =====
// ============================
libandroid.so
libz.so
libEGL.so
libmediandk.so
libm.so
libdl.so
libc.so
