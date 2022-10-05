/**
 * @file monitor.h
 * @note Copyright (C) [2021-2022] Renesas Electronics Corporation and/or its affiliates
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2, as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */
/********************************************************************************************************************
* Release Tag: 1-0-4
* Pipeline ID: 125967
* Commit Hash: 97f7354c
********************************************************************************************************************/

#ifndef MONITOR_H
#define MONITOR_H

#include "../common/common.h"
#include "../common/os.h"
#include "../common/types.h"

typedef struct {
  T_esmc_ql lo_ql;
  T_esmc_ql holdover_ql;
  unsigned int holdover_timer_s; /* Seconds */
} T_monitor_config;

typedef struct {
  unsigned int holdover_timer_s;                 /* Seconds */
  unsigned long long holdover_monotonic_time_ms;
  T_device_dpll_state current_synce_dpll_state;
  T_esmc_ql current_ql;
  int current_clk_idx;
  int current_sync_idx;
} T_monitor_data;

int monitor_init(T_monitor_config const *monitor_config);
void monitor_determine_ql(void);
void monitor_get_current_status(T_esmc_ql *current_ql,
                                char *port_name,
                                int *clk_idx,
                                T_device_dpll_state *dpll_state,
                                unsigned int *holdover_remaining_time_ms);

void monitor_clear_holdover_timer(void);
int monitor_deinit(void);

#endif /* MONITOR_H */
