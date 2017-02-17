/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "vendor_init.h"
#include <cutils/properties.h>
#include "log.h"
#include "util.h"
#include <sys/system_properties.h>

void init_variant_properties() {
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    rc = property_get("ro.board.platform", platform, NULL);
    if (!rc || strncmp(platform, ANDROID_TARGET, PROP_VALUE_MAX))
        return;

    property_get("ro.bootloader", bootloader, NULL);;

    if (strstr(bootloader, "N915FY")) {
        /* tbltexx These values are taken from tbltexx and edited for the 915FY FIXME */
        property_set("ro.build.fingerprint", "samsung/tbltebtu/tblte:6.0.1/MMB29M/N915FYXXS1DPG1:user/release-keys");
        property_set("ro.build.description", "tbltebtu-user 6.0.1 MMB29M N915FYXXS1DPG1 release-keys");
        property_set("ro.product.model", "SM-N915FY");
        property_set("ro.product.device", "tbltexx");
    } else if (strstr(bootloader, "N915G")) {
         /* tbltedt */
         property_set("ro.build.fingerprint", "samsung/tbltebtu/tblte:6.0.1/MMB29M/N915FYXXS1DPG1:user/release-keys");
        property_set("ro.build.description", "tbltebtu-user 6.0.1 MMB29M N915FYXXS1DPG1 release-keys");
         property_set("ro.product.model", "SM-N915G");
         property_set("ro.product.device", "tbltedt");
    } else {
        /* tblte */
        property_set("ro.build.fingerprint", "samsung/tbltebtu/tblte:6.0.1/MMB29M/N915FYXXS1DPG1:user/release-keys");
        property_set("ro.build.description", "tbltebtu-user 6.0.1 MMB29M N915FYXXS1DPG1 release-keys");
        property_set("ro.product.model", "SM-N915F");
        property_set("ro.product.device", "tblte");
    }

    property_get("ro.product.device", device, NULL);
    strlcpy(devicename, device, sizeof(devicename));
    ERROR("Found bootloader id %s setting build properties for %s device\n", bootloader, devicename);
}
