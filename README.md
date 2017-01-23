# C-- [![Build Status](https://travis-ci.org/Manu343726/C--.svg?branch=master)](https://travis-ci.org/Manu343726/C--) [![Join the chat at https://gitter.im/Manu343726-cminusminus/Lobby](https://badges.gitter.im/Manu343726-cminusminus/Lobby.svg)](https://gitter.im/Manu343726-cminusminus/Lobby?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)
The sandbox where we show our increasingly depressing C++ skills

## Dependencies

 - **[CMake > 2.8](https://cmake.org/)** as buildsystem.
 - **[conan.io](https://www.conan.io/)** as package manager.
 - **[Google Test](https://github.com/google/googletest) and [Google Mock](https://github.com/google/googlemock)** for unit testing (From conan.io)
 - **A C++14 compiler** GCC 5.1 or clang 3.8 if possible. VS2015 may work.

## How we work

The project defines a set of exercises to learn C++ or to improve the existing skills. Each exercise works as a full
library defined in the project itself (So each finished exercise becomes a module of the library that this C-- project is).

The project follows an `include/` `src/` `test/` sourcetree layout, where:

 - `include/siminusminus/`: Contains the headers of the project (one subdirectory per module, see instructions bellow), 
 - `src/`: Contains the implementation files (.cpp files) of the project, one subdirectory per module.
 - `test/`: Unit tests, one subdirectory per module.

### How exercises are defined:

The description of the exercise will be provided **as an issue tagged as `exercise`, numbered with the issue number**.
Multiple exercises may be part of a same topic, each topic represented as a module in the project (Data structures, utilities, etc).

The exercise may include or not all the bootstrapping stuff, like adding CMakeLists.txt files at the corresponding directories for
library and tests targets, new dependencies, etc.

Exercises may depend in already-solved exercises, for example an exercise about writing an `string_view` from a `string` class written
in a previous one.

### Development rules:

 1. Exercises are solved in feature branches named `dev/exercise-n` coming from `master`, where n is the number of the exercise.
 2. To submit the exercise, send a PR to the master branch (A PR that tries to merge the exercise branch into master). **Always use the
    github interface to open the PR. Never merge to master directly.**
 3. Proper doxygen documentation adds extra points.
 4. A submitted exercise **must contain unit tests**.
 5. To accept the submission, unit tests must pass on the CI build (Both on the branch and the PR).

## License

C-- is license under the MIT license. See LICENSE for details.
