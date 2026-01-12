if ($ENV{TRIGGER_CCG_VIOLATION})
  add_executable(provoke.cppcoreguidelines-avoid-goto cppcoreguidelines-avoid-goto.cpp)
  add_test(provoke.cppcoreguidelines-avoid-goto provoke.cppcoreguidelines-avoid-goto)
endif ()

if ($ENV{TRIGGER_SANITIZER})
  add_executable(provoke.overflow provoke.overflow.cpp)
  add_test(provoke.overflow provoke.overflow)
endif ()

if ($ENV{TRIGGER_COMPILER_WARNING})
  add_executable(provoke.unused-label provoke.unused-label.cpp)
  add_test(provoke.unused-label provoke.unused-label)
endif ()
