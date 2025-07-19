//did not see the distribution code so made it my self 
#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    int vote_Count;
} candidate;

void register_Vote(int num_Of_Candidates, candidate *candidates);
void winner_SideEffect(int num_Of_Candidates, candidate *candidates);

int main(int argc, char *argv[])
{
    int vote_Total = get_int("number of voters:");
    candidate candidates[argc - 1];

    for (int position = 0; position < argc-1; position++)
    {
        candidates[position].name = argv[position+1];
        candidates[position].vote_Count = 0;
    }

    for (int current_Vote = 0; current_Vote < vote_Total; current_Vote++)
    {
        register_Vote(argc-1, candidates);
    }
    winner_SideEffect(argc-1, candidates);
    return 0;
}

void register_Vote(int num_Of_Candidates, candidate *candidates)
{
    string vote_Name = get_string("vote: ");
    for (int candidate_Number = 0; candidate_Number < num_Of_Candidates; candidate_Number++)
    {
        if (strcmp(candidates[candidate_Number].name, vote_Name) == 0)
        {
            candidates[candidate_Number].vote_Count += 1;
            return;
        }
    }
    printf("invalid vote\n");
}

void winner_SideEffect(int num_Of_Candidates, candidate *candidates)
{
    candidate top_candidate = candidates[0];
    for (int candidate_Number = 1; candidate_Number < num_Of_Candidates; candidate_Number++)
    {
        if (candidates[candidate_Number].vote_Count > top_candidate.vote_Count)
        {
            top_candidate = candidates[candidate_Number];
        }
    }
    printf("%s\n", top_candidate.name);
}
