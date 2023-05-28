/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** exec_instruction
*/

#include "corewar_type.h"
#include "macros.h"
#include "corewar_proto.h"
#include "corewar_macros.h"
#include "op.h"
#include "my.h"
#include "instruction.h"
#include <stdbool.h>

bool is_finished(corewar_t *core)
{
    bool champ_alive_detected = false;

    for (int i = 0; i < core->nb_original_prog; ++i) {
        if (core->all_names[i].time_left > 0
        && champ_alive_detected == true) {
            return false;
        }
        if (core->all_names[i].time_left > 0
        && champ_alive_detected == false) {
            champ_alive_detected = true;
        }
    }
    return true;
}

static int exec_instruction(corewar_t *core, process_t *process)
{
    octet_t instruction = core->mem[process->PC];

    process->wait += 1;
    if (process->time_left < 0) {
        return SUCESS;
    }
    process->time_left -= core->cycle_delta;
    if (!IS_INSTRUCTION(instruction)) {
        process->PC = (process->PC + 1) % MEM_SIZE;
        return SUCESS;
    }
    return all_instruction[(int)instruction - 1](core->mem, process);
}

static void update_names(corewar_t *core)
{
    for (int j = 0; j < core->nb_original_prog; ++j) {
        if (core->all_names[j].time_left > 0) {
            core->all_names[j].time_left -= core->cycle_delta;
        }
    }
}

static void display_winner(corewar_t *core)
{
    for (int i = 0; i < core->nb_original_prog; ++i) {
        if (core->all_names[i].time_left > -1) {
            my_putstr("Le joueur ");
            my_putnbr(core->all_names[i].id);
            my_putstr(" (");
            my_putstr(core->all_names[i].name);
            my_putstr(") a gagné.\n");
            return;
        }
    }
}

int run_corewar(corewar_t *core, long dump)
{
    long i = 0;
    bool run = true;

    for (; i != dump && run; ++i) {
        if (i + 1 < 0)
            i = 0;
        for (int j = 0; j < core->nb_prog && run; ++j) {
            exec_instruction(core, &(core->progs[j]));
            run = !is_finished(core);
        }
        update_names(core);
    }
    if (is_finished(core)) {
        display_winner(core);
    }
    if (dump != -1) {
        display_memory(core->mem);
    }
    return 0;
}
