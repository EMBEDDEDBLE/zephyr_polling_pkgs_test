from building import *
import rtconfig

cwd = GetCurrentDir()
path = []
src = []

# Include stack info
stack_path = cwd + '/src'
path += [stack_path]

print("stack_path: %s", stack_path)
print("path: %s", path)

tmp_path = stack_path
src += Glob(tmp_path + '/*.c')
tmp_path = stack_path + '/base'
print("tmp_path: %s", tmp_path)
src += Glob(tmp_path + '/*.c')
tmp_path = stack_path + '/bluetooth'
src += Glob(tmp_path + '/*.c')
tmp_path = stack_path + '/common'
src += Glob(tmp_path + '/*.c')
tmp_path = stack_path + '/drivers'
src += Glob(tmp_path + '/*.c')
tmp_path = stack_path + '/host'
src += Glob(tmp_path + '/*.c')
tmp_path = stack_path + '/logging'
src += Glob(tmp_path + '/*.c')
tmp_path = stack_path + '/utils'
src += Glob(tmp_path + '/*.c')
tmp_path = stack_path + '/services'
src += Glob(tmp_path + '/*.c')

print("src0: %s", src)

app = GetConfigValue('PKG_ZEPHYR_POLLING_APP').replace('"', '')
chipset = GetConfigValue('PKG_ZEPHYR_POLLING_CHIPSET').replace('"', '')
porting = GetConfigValue('PKG_ZEPHYR_POLLING_PORTING').replace('"', '')

print("app: %s", app)

tmp_path = cwd + '/example/' + app
path += [tmp_path]
src += Glob(tmp_path + '/*.c')

print("src1: %s", src)

tmp_path = cwd + '/chipset/'
path += [tmp_path]
tmp_path = tmp_path + chipset
path += [tmp_path]
src += Glob(tmp_path + '/*.c')

print("src2: %s", src)

tmp_path = cwd + '/platform/'
path += [tmp_path]
tmp_path = tmp_path + 'rtthread'
path += [tmp_path]
src += Glob(tmp_path + '/*.c')

tmp_path = cwd + '/porting/'
path += [tmp_path]
tmp_path = tmp_path + porting
path += [tmp_path]
src += Glob(tmp_path + '/*.c')

print("src3: %s", src)

print("path: %s", path)

# if rtconfig.CROSS_TOOL == 'keil':
#     LOCAL_CCFLAGS += ' --gnu --diag_suppress=111'
    
group = DefineGroup('zephyr_polling', src, depend = ['PKG_USING_ZEPHYR_POLLING'], CPPPATH = path)

Return('group')
