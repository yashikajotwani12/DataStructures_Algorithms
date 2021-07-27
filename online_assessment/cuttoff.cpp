// Parameters:
// scores : List of int
// cutOffRank : int
// num: int (denoting amount of scores)

// You are given a list of integers representing scores of players in a video game. Players can 'level-up' if by the end of the game they have a rank that is at least the cutOffRank. A player's rank is solely determined by their score relative to the other players' scores. For example:

// Score : 10 | Rank 1
// Score : 5 | Rank 2
// Score : 3 | Rank 3
// etc.

// If multiple players happen to have the same score, then they will all receive the same rank. However, the next player with a score lower than theirs will receive a rank that is offset by this. For example:

// Score: 10 | Rank 1
// Score: 10 | Rank 1
// Score: 10 | Rank 1
// Score : 5 | Rank 4

// Finally, any player with a score of 0 is automatically ineligible for leveling-up, regardless of their rank.

// Return the number of players who are eligible for leveling-up