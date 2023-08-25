from functools import reduce


while True:
    qtd_cmds = input()
    if qtd_cmds == "0":
        break
    qtd_cmds = int(qtd_cmds)
    cmds = list(map(int, input().split()))
    init_tuple: tuple[int, int, list[int]] = (0, 0, [])
    _, qtd_actions, _ = reduce(
        lambda agg, next_cmd: (
            agg[0] + 1,
            (agg[2].index(next_cmd) + 1 if next_cmd in agg[2] else (agg[0] + next_cmd))
            + agg[1],
            [next_cmd, *agg[2]],
        ),
        cmds,
        init_tuple,
    )
    print(qtd_actions)
