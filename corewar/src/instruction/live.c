/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** live
*/

#include "macros.h"
#include "corewar_macros.h"
#include "corewar_type.h"
#include "corewar_proto.h"
#include "my.h"

static void diplay_alive(char const *name, int id)
{
    my_putstr("le joueur ");
    my_putnbr(id);
    my_putstr(" (");
    my_putstr(name);
    my_putstr(") est en vie.");
}

int live(octet_t memory[MEM_SIZE], process_t *process)
{
    int i = 1;
    int player_number;
    corewar_t *core = corewar_store();

    if (process->wait < 10)
        return SUCESS;
    i += process->PC;
    player_number = GET_MEM_DIR(memory, &i);
    for (int j = 0; j < core->nb_original_prog; ++j) {
        if (core->all_names[j].id == player_number) {
            diplay_alive(core->all_names[j].name, core->all_names[j].id);
        }
    }
    for (int i = 0; i < core->nb_processes; ++i) {
        if (core->processes[i].registers[0] == player_number)
            core->processes[i].time_left = CYCLE_TO_DIE;
    }
    reset_process(process, 5);
    return SUCESS;
}
