# Copyright (C) 2014 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# inherit from common tblte
-include device/samsung/tblte-common/BoardConfigCommon.mk

TARGET_OTA_ASSERT_DEVICE := tblte,tbltexx,tbltedt,tbltetmo

# Partitions
BOARD_FLASH_BLOCK_SIZE := 262144
TARGET_USERIMAGES_USE_EXT4 := true
BOARD_BOOTIMAGE_PARTITION_SIZE := 17825792
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 19922944
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 3774873600
BOARD_USERDATAIMAGE_PARTITION_SIZE := 27019685888

# Kernel
TARGET_KERNEL_VARIANT_CONFIG := aklu_tblte_eur_defconfig
# Prebuilt kernel if you need it, works.
# TARGET_PREBUILT_KERNEL := ../../..device/samsung/tbltexx/kernel

# Camera
TARGET_FIXUP_PREVIEW := true

#TW_THEME
TW_THEME := portrait_hdpi

# Init
#TARGET_INIT_VENDOR_LIB := libinit_msm
#TARGET_LIBINIT_DEFINES_FILE := device/samsung/tbltexx/init/init_tblte.cpp
TARGET_UNIFIED_DEVICE := true

# Radio
BOARD_RIL_CLASS := ../../../device/samsung/tbltexx/ril

# inherit from the proprietary version
-include vendor/samsung/tbltexx/BoardConfigVendor.mk
