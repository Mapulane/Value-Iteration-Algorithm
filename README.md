# Value-Iteration-Algorithm

Implement (in C++) the Value Iteration algorithm (detailed in chapter 3
[Sutton and Barto, 1998] and chapter 13 [Mitchell, 1997]) in order to find the
optimal value (V ∗ ) for each state in a small grid-world (figure 1). Use the fol-
lowing information:

1. The agent has 4 actions { left, right, up, down }, and the grid-world 6
states { s 1 , s 2 , s 3 , s 4 , s 5 , s 6 }. Figure 1 shows the possible transitions
between states (actions for given states).

2. The state transition distribution Pa ss
′ is deterministic, so P ass ′ = 1.0 for all
states and actions.

3. Rewards for all state transitions are zero (Ra ss
′ = 0), except the following:
a
(1, 1) → (2, 1); R ss
′ =50
a
(2, 0) → (2, 1); R ss
′ =100
4. State s 3 is the terminal state.
5. The discount factor is 0.8, i.e. γ = 0.8.
