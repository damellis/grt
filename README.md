# Gesture Recognition Toolkit (GRT)

The (Gesture Recognition Toolkit (GRT))[http://nickgillian.com/grt/] is a cross-platform, open-source, C++ machine learning library designed for real-time gesture recognition. This repository is an effort to port the GRT to run on microcontrollers, specifically Arduino boards. Despite the name of the branch, currently the only supported hardware is the Arduino Due, which contains an ARM Cortex M3 processor. 

## Setup

To use the GRT with the Arduino Due, you'll need to place this repository in the libraries/ folder in your Arduino sketchbook folder. Also, make sure you've added SAM support from the Arduino boards manager. You'll also need to add the following files to a folder called hardware/cpp/sam in your Arduino sketchbook folder: platform.local.txt:

```
compiler.c.elf.cmd=arm-none-eabi-g++
```

boards.txt:

```
arduino_due_x_dbg.name=Arduino Due w/ STL (Programming Port)
arduino_due_x_dbg.vid.0=0x2341
arduino_due_x_dbg.pid.0=0x003d
arduino_due_x_dbg.vid.1=0x2A03
arduino_due_x_dbg.pid.1=0x003d
arduino_due_x_dbg.upload.tool=arduino:bossac
arduino_due_x_dbg.upload.protocol=sam-ba
arduino_due_x_dbg.upload.maximum_size=524288
arduino_due_x_dbg.upload.use_1200bps_touch=true
arduino_due_x_dbg.upload.wait_for_upload_port=false
arduino_due_x_dbg.upload.native_usb=false
arduino_due_x_dbg.build.mcu=cortex-m3
arduino_due_x_dbg.build.f_cpu=84000000L
arduino_due_x_dbg.build.usb_product="Arduino Due"
arduino_due_x_dbg.build.board=SAM_DUE
arduino_due_x_dbg.build.core=arduino:arduino
arduino_due_x_dbg.build.extra_flags=-D__SAM3X8E__ -mthumb {build.usb_flags} -Dprintf=printf
arduino_due_x_dbg.build.ldscript=linker_scripts/gcc/flash.ld
arduino_due_x_dbg.build.variant=arduino:arduino_due_x
arduino_due_x_dbg.build.variant_system_lib=libsam_sam3x8e_gcc_rel.a
arduino_due_x_dbg.build.vid=0x2341
arduino_due_x_dbg.build.pid=0x003e

arduino_due_x.name=Arduino Due w/ STL (Native USB Port)
arduino_due_x.vid.0=0x2341
arduino_due_x.pid.0=0x003e
arduino_due_x.vid.1=0x2A03
arduino_due_x.pid.1=0x003e
arduino_due_x.upload.tool=arduino:bossac
arduino_due_x.upload.protocol=sam-ba
arduino_due_x.upload.maximum_size=524288
arduino_due_x.upload.use_1200bps_touch=true
arduino_due_x.upload.wait_for_upload_port=true
arduino_due_x.upload.native_usb=true
arduino_due_x.build.mcu=cortex-m3
arduino_due_x.build.f_cpu=84000000L
arduino_due_x.build.usb_product="Arduino Due"
arduino_due_x.build.board=SAM_DUE
arduino_due_x.build.core=arduino:arduino
arduino_due_x.build.extra_flags=-D__SAM3X8E__ -mthumb {build.usb_flags} -Dprintf=printf
arduino_due_x.build.ldscript=linker_scripts/gcc/flash.ld
arduino_due_x.build.variant=arduino:arduino_due_x
arduino_due_x.build.variant_system_lib=libsam_sam3x8e_gcc_rel.a
arduino_due_x.build.vid=0x2341
arduino_due_x.build.pid=0x003e
```

##License

The Gesture Recognition Toolkit is available under a MIT license.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
