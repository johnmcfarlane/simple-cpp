if ($ENV{TRIGGER_CCG_VIOLATION})
  add_executable(trigger.cppcoreguidelines-avoid-goto trigger.cppcoreguidelines-avoid-goto.cpp)
  add_test(trigger.cppcoreguidelines-avoid-goto trigger.cppcoreguidelines-avoid-goto)
endif ()

if ($ENV{TRIGGER_MT_BUG})
  add_executable(trigger.data-race trigger.data-race.cpp)
  add_test(trigger.data-race trigger.data-race)
endif ()

if ($ENV{TRIGGER_INTEGER_BUG})
  add_executable(trigger.integer-overflow trigger.integer-overflow.cpp)
  add_test(trigger.integer-overflow trigger.integer-overflow)
endif ()

if ($ENV{TRIGGER_STDLIB_BUG})
  add_executable(trigger.vector-overflow trigger.vector-overflow.cpp)
  add_test(trigger.vector-overflow trigger.vector-overflow)
endif ()

if ($ENV{TRIGGER_COMPILER_WARNING})
  add_executable(trigger.unused-label trigger.unused-label.cpp)
  add_test(trigger.unused-label trigger.unused-label)
endif ()
