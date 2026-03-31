# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/mnt/c/Users/Gianl/OneDrive/Documenti/GitHub_Projects/Z80DevBoard/firmware/pico-sdk/tools/pioasm"
  "/mnt/c/Users/Gianl/OneDrive/Documenti/GitHub_Projects/Z80DevBoard/firmware/build/pioasm"
  "/mnt/c/Users/Gianl/OneDrive/Documenti/GitHub_Projects/Z80DevBoard/firmware/build/pioasm-install"
  "/mnt/c/Users/Gianl/OneDrive/Documenti/GitHub_Projects/Z80DevBoard/firmware/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/tmp"
  "/mnt/c/Users/Gianl/OneDrive/Documenti/GitHub_Projects/Z80DevBoard/firmware/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/pioasmBuild-stamp"
  "/mnt/c/Users/Gianl/OneDrive/Documenti/GitHub_Projects/Z80DevBoard/firmware/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src"
  "/mnt/c/Users/Gianl/OneDrive/Documenti/GitHub_Projects/Z80DevBoard/firmware/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/pioasmBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/mnt/c/Users/Gianl/OneDrive/Documenti/GitHub_Projects/Z80DevBoard/firmware/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/pioasmBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/mnt/c/Users/Gianl/OneDrive/Documenti/GitHub_Projects/Z80DevBoard/firmware/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/pioasmBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
