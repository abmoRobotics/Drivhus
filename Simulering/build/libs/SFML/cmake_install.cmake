# Install script for directory: C:/Users/anton/Google Drev/Andet/Uni(Drev)/2. Semester/SSP/3. Øvelser/SSP_greenhouseWorkshop1/libs/SFML

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/greenhouse_controller")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE DIRECTORY FILES "C:/Users/anton/Google Drev/Andet/Uni(Drev)/2. Semester/SSP/3. Øvelser/SSP_greenhouseWorkshop1/libs/SFML/include" FILES_MATCHING REGEX "/[^/]*\\.hpp$" REGEX "/[^/]*\\.inl$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE DIRECTORY FILES "C:/Users/anton/Google Drev/Andet/Uni(Drev)/2. Semester/SSP/3. Øvelser/SSP_greenhouseWorkshop1/build/libs/SFML/lib" FILES_MATCHING REGEX "/[^/]*\\.pdb$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "C:/Users/anton/Google Drev/Andet/Uni(Drev)/2. Semester/SSP/3. Øvelser/SSP_greenhouseWorkshop1/libs/SFML/license.md")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "C:/Users/anton/Google Drev/Andet/Uni(Drev)/2. Semester/SSP/3. Øvelser/SSP_greenhouseWorkshop1/libs/SFML/readme.md")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./bin" TYPE DIRECTORY FILES "C:/Users/anton/Google Drev/Andet/Uni(Drev)/2. Semester/SSP/3. Øvelser/SSP_greenhouseWorkshop1/libs/SFML/extlibs/bin/x64/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./lib" TYPE DIRECTORY FILES "C:/Users/anton/Google Drev/Andet/Uni(Drev)/2. Semester/SSP/3. Øvelser/SSP_greenhouseWorkshop1/libs/SFML/extlibs/libs-msvc-universal/x64/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SFML/SFMLSharedTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SFML/SFMLSharedTargets.cmake"
         "C:/Users/anton/Google Drev/Andet/Uni(Drev)/2. Semester/SSP/3. Øvelser/SSP_greenhouseWorkshop1/build/libs/SFML/CMakeFiles/Export/lib/cmake/SFML/SFMLSharedTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SFML/SFMLSharedTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SFML/SFMLSharedTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SFML" TYPE FILE FILES "C:/Users/anton/Google Drev/Andet/Uni(Drev)/2. Semester/SSP/3. Øvelser/SSP_greenhouseWorkshop1/build/libs/SFML/CMakeFiles/Export/lib/cmake/SFML/SFMLSharedTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SFML" TYPE FILE FILES "C:/Users/anton/Google Drev/Andet/Uni(Drev)/2. Semester/SSP/3. Øvelser/SSP_greenhouseWorkshop1/build/libs/SFML/CMakeFiles/Export/lib/cmake/SFML/SFMLSharedTargets-debug.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SFML" TYPE FILE FILES
    "C:/Users/anton/Google Drev/Andet/Uni(Drev)/2. Semester/SSP/3. Øvelser/SSP_greenhouseWorkshop1/build/libs/SFML/SFMLConfig.cmake"
    "C:/Users/anton/Google Drev/Andet/Uni(Drev)/2. Semester/SSP/3. Øvelser/SSP_greenhouseWorkshop1/build/libs/SFML/SFMLConfigDependencies.cmake"
    "C:/Users/anton/Google Drev/Andet/Uni(Drev)/2. Semester/SSP/3. Øvelser/SSP_greenhouseWorkshop1/build/libs/SFML/SFMLConfigVersion.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/anton/Google Drev/Andet/Uni(Drev)/2. Semester/SSP/3. Øvelser/SSP_greenhouseWorkshop1/build/libs/SFML/src/SFML/cmake_install.cmake")

endif()

