/*
 * Copyright 2016 RIFT.IO Inc
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _RW_PMD_RAW_H_
#define _RW_PMD_RAW_H_

#ifdef __cplusplus
extern "C" {
#endif

#define RTE_RW_PMD_RAW_PARAM_NAME "eth_raw"

#define RW_PMD_RAW_IFNAME_LEN 64

#ifndef ASSERT
#define ASSERT assert
#endif

/**
 * For use by the EAL only. Called as part of EAL init to set up any dummy NICs
 * configured on command line.
 */
   
int rw_pmd_raw_init(const char *name, const char *params); 
#ifdef __cplusplus
}
#endif

#endif
