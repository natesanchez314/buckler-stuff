# nRF application makefile
PROJECT_NAME = $(shell basename "$(realpath ./)")

# Configurations
NRF_IC = nrf52832
SDK_VERSION = 15
SOFTDEVICE_MODEL = s132

# Path to free RTOS
FREE_RTOS_DIR = ./FreeRTOS-Kernel/

# Source and header files
APP_HEADER_PATHS += .
APP_HEADER_PATHS += $(FREE_RTOS_DIR)include/
APP_HEADER_PATHS += $(FREE_RTOS_DIR)portable/GCC/nrf52/

APP_SOURCE_PATHS += .
APP_SOURCES = $(notdir $(wildcard ./*.c))
APP_SOURCES += $(wildcard $(FREE_RTOS_DIR)*.c)
APP_SOURCES += $(wildcard $(FREE_RTOS_DIR)portable/GCC/nrf52/*.c)
APP_SOURCES +=  $(FREE_RTOS_DIR)portable/MemMang/heap_2.c

# Path to base of nRF52-base repo
NRF_BASE_DIR = ../../nrf52x-base/
# $(info $$APP_SOURCES is [${APP_SOURCES}])
# Include board Makefile (if any)
include ../../boards/buckler_revC/Board.mk

# Include main Makefile./main.c
include $(NRF_BASE_DIR)make/AppMakefile.mk
