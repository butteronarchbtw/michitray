project(
  'michitray',
  'cpp',
)

libayatana_appindicator_dep = dependency(
  'ayatana-appindicator3-0.1',
  required: true,
)
miniaudio_dep = dependency('miniaudio', required: true)
gtk_dep = dependency('gtk+-3.0', required: true)
libconfig_dep = dependency('libconfig', required: true)
catch2_dep = dependency('catch2-with-main', required: true, default_options: ['tests=false'])

subdir('src')
subdir('mp3')
subdir('tests')
