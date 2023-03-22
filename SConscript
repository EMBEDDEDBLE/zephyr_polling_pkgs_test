from building import *
import rtconfig

cwd = GetCurrentDir()
path = []
src = []

# Include stack info
tmpPath = cwd + '/src'
path += tmpPath
src += GlobSubDir(tmpPath, '*.c')

app = GetConfigValue('PKG_ZEPHYR_POLLING_APP')
chipset = GetConfigValue('PKG_ZEPHYR_POLLING_CHIPSET')
porting = GetConfigValue('PKG_ZEPHYR_POLLING_PORTING')


tmpPath = cwd + '/example/' + app
path += tmpPath
src += GlobSubDir(tmpPath, '*.c')


tmpPath = cwd + '/chipset/' + chipset
path += tmpPath
src += GlobSubDir(tmpPath, '*.c')


tmpPath = cwd + '/porting/' + porting
path += tmpPath
src += GlobSubDir(tmpPath, '*.c')

CPPDEFINES = ''
LOCAL_CCFLAGS = ''

# if rtconfig.CROSS_TOOL == 'keil':
#     LOCAL_CCFLAGS += ' --gnu --diag_suppress=111'
    
group = DefineGroup('zephyr_polling', src, depend = ['PKG_USING_ZEPHYR_POLLING'], CPPPATH = path, CPPDEFINES = CPPDEFINES, LOCAL_CCFLAGS = LOCAL_CCFLAGS)

Return('group')
