# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/emmak/Documents/wlc_folder/csc_homework/game_dev/class-game/cmake-build-debug/_deps/sdl-src"
  "C:/Users/emmak/Documents/wlc_folder/csc_homework/game_dev/class-game/cmake-build-debug/_deps/sdl-build"
  "C:/Users/emmak/Documents/wlc_folder/csc_homework/game_dev/class-game/cmake-build-debug/_deps/sdl-subbuild/sdl-populate-prefix"
  "C:/Users/emmak/Documents/wlc_folder/csc_homework/game_dev/class-game/cmake-build-debug/_deps/sdl-subbuild/sdl-populate-prefix/tmp"
  "C:/Users/emmak/Documents/wlc_folder/csc_homework/game_dev/class-game/cmake-build-debug/_deps/sdl-subbuild/sdl-populate-prefix/src/sdl-populate-stamp"
  "C:/Users/emmak/Documents/wlc_folder/csc_homework/game_dev/class-game/cmake-build-debug/_deps/sdl-subbuild/sdl-populate-prefix/src"
  "C:/Users/emmak/Documents/wlc_folder/csc_homework/game_dev/class-game/cmake-build-debug/_deps/sdl-subbuild/sdl-populate-prefix/src/sdl-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/emmak/Documents/wlc_folder/csc_homework/game_dev/class-game/cmake-build-debug/_deps/sdl-subbuild/sdl-populate-prefix/src/sdl-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/emmak/Documents/wlc_folder/csc_homework/game_dev/class-game/cmake-build-debug/_deps/sdl-subbuild/sdl-populate-prefix/src/sdl-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
