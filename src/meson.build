lib_src = [
  'App.cpp',
  'Sound.cpp',
  'Config.cpp',
  'TrayMenu.cpp',
  'Indicator.cpp',
]

main_src = [
  'main.cpp',
]

lib_deps = [
  miniaudio_dep,
  gtk_dep,
  libayatana_appindicator_dep,
  libconfig_dep,
]

michitray_lib = library(
  'michitray-lib',
  lib_src,
  dependencies: lib_deps,
)

michitray_ngtk_lib = library(
  'michitray-lib-ngtk',
  lib_src,
  dependencies: [miniaudio_dep, libconfig_dep],
  cpp_args: ['-DNGTK'],
)

michitray_dep = declare_dependency(
  link_with: michitray_lib,
  include_directories: include_directories('.'),
  dependencies: lib_deps,
)

michitray_ngtk_dep = declare_dependency(
  link_with: michitray_ngtk_lib,
  include_directories: include_directories('.'),
  dependencies: [miniaudio_dep, libconfig_dep],
)

main_exe = executable(
  'michitray',
  main_src,
  dependencies: [
    gtk_dep,
    michitray_dep,
  ],
)
