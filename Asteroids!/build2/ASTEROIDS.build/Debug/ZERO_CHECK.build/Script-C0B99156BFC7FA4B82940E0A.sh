#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/wufangzheng/Documents/phd/graphics/moon-2/MoonPatrol/Asteroids!/build2
  make -f /Users/wufangzheng/Documents/phd/graphics/moon-2/MoonPatrol/Asteroids!/build2/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/wufangzheng/Documents/phd/graphics/moon-2/MoonPatrol/Asteroids!/build2
  make -f /Users/wufangzheng/Documents/phd/graphics/moon-2/MoonPatrol/Asteroids!/build2/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/wufangzheng/Documents/phd/graphics/moon-2/MoonPatrol/Asteroids!/build2
  make -f /Users/wufangzheng/Documents/phd/graphics/moon-2/MoonPatrol/Asteroids!/build2/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/wufangzheng/Documents/phd/graphics/moon-2/MoonPatrol/Asteroids!/build2
  make -f /Users/wufangzheng/Documents/phd/graphics/moon-2/MoonPatrol/Asteroids!/build2/CMakeScripts/ReRunCMake.make
fi

