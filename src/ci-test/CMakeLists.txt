if ($ENV{TRIGGER_CCG_VIOLATION})
  add_executable(trigger.cppcoreguidelines-avoid-goto trigger.cppcoreguidelines-avoid-goto.cpp)
  add_test(trigger.cppcoreguidelines-avoid-goto trigger.cppcoreguidelines-avoid-goto)
endif ()

if ($ENV{TRIGGER_SANITIZER})
  add_executable(trigger.overflow trigger.overflow.cpp)
  add_test(trigger.overflow trigger.overflow)
endif ()

if ($ENV{TRIGGER_COMPILER_WARNING})
  add_executable(trigger.unused-label trigger.unused-label.cpp)
  add_test(trigger.unused-label trigger.unused-label)
endif ()
