if ($ENV{PROVOKE_CCG})
  add_executable(provoke.cppcoreguidelines-avoid-goto cppcoreguidelines-avoid-goto.cpp)
  add_test(provoke.cppcoreguidelines-avoid-goto provoke.cppcoreguidelines-avoid-goto)
endif ()

if ($ENV{PROVOKE_SANITIZER})
  add_executable(provoke.overflow provoke.overflow.cpp)
  add_test(provoke.overflow provoke.overflow)
endif ()

if ($ENV{PROVOKE_WARNING})
  add_executable(provoke.missing-return provoke.missing-return.cpp)
  add_test(provoke.missing-return provoke.missing-return)
endif ()
