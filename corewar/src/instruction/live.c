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

static void display_alive(char const *name, int id)
{
    my_putstr("Le joueur ");
    my_putnbr(id);
    my_putstr(" (");
    my_putstr(name);
    my_putstr(") est en vie.\n");
}

int live(octet_t memory[MEM_SIZE], process_t *process)
{
    int i = process->PC + 1;
    int player_number = 0;
    corewar_t *core = corewar_store();

    if (process->wait < op_tab[LIVE].nbr_cycles)
        return SUCESS;
    player_number = GET_MEM_DIR(memory, &i);
    for (int j = 0; j < core->nb_original_prog; ++j) {
        if (core->all_names[j].id == player_number) {
            display_alive(core->all_names[j].name, core->all_names[j].id);
            core->all_names[j].time_left = CYCLE_TO_DIE;
        }
    }
    core->nb_live_called += 1;
    core->cycle_delta = (core->nb_live_called >= NBR_LIVE) ? CYCLE_DELTA : 1;
    for (int i = 0; i < core->nb_prog; ++i)
        if (core->progs[i].registers[0] == player_number)
            core->progs[i].time_left = CYCLE_TO_DIE;
    reset_process(process, process->PC + 5);
    return SUCESS;
}
