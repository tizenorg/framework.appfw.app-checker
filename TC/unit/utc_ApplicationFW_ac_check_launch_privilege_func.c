/*
 *  app-checker
 *
 * Copyright (c) 2000 - 2011 Samsung Electronics Co., Ltd. All rights reserved.
 *
 * Contact: Jayoun Lee <airjany@samsung.com>, Sewook Park <sewook7.park@samsung.com>,
 * Jaeho Lee <jaeho81.lee@samsung.com>, Shobhit Srivastava <shobhit.s@samsung.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <tet_api.h>
#include <app-checker.h>
#include <unistd.h>
#include <sys/types.h>

static void startup(void);
static void cleanup(void);

void (*tet_startup) (void) = startup;
void (*tet_cleanup) (void) = cleanup;

static void utc_ApplicationFW_ac_check_launch_privilege_func_01(void);
static void utc_ApplicationFW_ac_check_launch_privilege_func_02(void);
static void utc_ApplicationFW_ac_check_launch_privilege_func_03(void);
static void utc_ApplicationFW_ac_check_launch_privilege_func_04(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{utc_ApplicationFW_ac_check_launch_privilege_func_01, POSITIVE_TC_IDX},
	{utc_ApplicationFW_ac_check_launch_privilege_func_02, NEGATIVE_TC_IDX},
	{utc_ApplicationFW_ac_check_launch_privilege_func_03, NEGATIVE_TC_IDX},
	{utc_ApplicationFW_ac_check_launch_privilege_func_04, NEGATIVE_TC_IDX},
	{NULL, 0},
};

static void startup(void)
{
}

static void cleanup(void)
{
}

/** API Prototype
*int ac_check_launch_privilege(const char *pkg_name,
*			const char *pkg_type, int pid);
*/


/**
 * @brief Positive test case of ac_check_launch_privilege()
 */
static void utc_ApplicationFW_ac_check_launch_privilege_func_01(void)
{
	int r = AC_R_ERROR;
	r = ac_check_launch_privilege("com.samsung.calculator", "deb",
				      getpid());
	if (r < 0) {
		tet_infoline
		    ("ac_check_launch_privilege()"
		     " failed in positive test case");
		tet_result(TET_FAIL);
		return;
	}
	tet_result(TET_PASS);
}

/**
 * @brief Negative test case 01 of ac_check_launch_privilege()
 */
static void utc_ApplicationFW_ac_check_launch_privilege_func_02(void)
{
	int r = AC_R_ERROR;
	r = ac_check_launch_privilege(NULL, "deb", getpid());
	if (r != AC_R_EINVAL) {
		tet_infoline
		    ("ac_check_launch_privilege()"
		     " failed in negative test case");
		tet_result(TET_FAIL);
		return;
	}
	tet_result(TET_PASS);
}

/**
 * @brief Negative test case 02 of ac_check_launch_privilege()
 */
static void utc_ApplicationFW_ac_check_launch_privilege_func_03(void)
{
	int r = AC_R_ERROR;
	r = ac_check_launch_privilege("com.samsung.calculator", NULL, getpid());
	if (r != AC_R_EINVAL) {
		tet_infoline
		    ("ac_check_launch_privilege()"
		     " failed in negative test case");
		tet_result(TET_FAIL);
		return;
	}
	tet_result(TET_PASS);
}

/**
 * @brief Negative test case 03 of ac_check_launch_privilege()
 */
static void utc_ApplicationFW_ac_check_launch_privilege_func_04(void)
{
	int r = AC_R_ERROR;
	r = ac_check_launch_privilege(NULL, NULL, getpid());
	if (r != AC_R_EINVAL) {
		tet_infoline
		    ("ac_check_launch_privilege()"
		     " failed in negative test case");
		tet_result(TET_FAIL);
		return;
	}
	tet_result(TET_PASS);
}
