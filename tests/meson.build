tests_src = [
  'test.cpp',
]

michitray_test = executable(
  'michitray-test',
  tests_src,
  dependencies: [catch2_dep, michitray_ngtk_dep],
  cpp_args: ['-DNGTK'],
)

test(
  'unit tests',
  michitray_test,
  args: ['-r', 'tap'],
  workdir: meson.current_build_dir(),
)

configure_file(input: 'test.cfg', output: 'test.cfg', copy: true)
