# automation schedule

| task        | actuator    | cadence     | day    | time  |
| :---------- | :---------- | :---------: | -----: | ----: |
| smart short | smartd.conf | weekly      | sun    | 3-4   |
| smart long  | smartd.conf | monthly     | 2      | 4-5   |
| trim        | cron.d      | monthly     | 1      | 0024  |
| scrub       | cron.d      | semimonthly | 1,15   | 4     |
| deploy      | cron.d      | weekly      | mon    | 3     |

## main
| task        | actuator    | cadence     | day    | time  |
| :---------- | :---------- | :---------: | -----: | ----: |
| backup      | user cron   | daily       | *      | 1     |
| prune snaps | cron.d      | weekly      | tue    | 3     |

## backup
| task        | actuator    | cadence     | day    | time  |
| :---------- | :---------- | :---------: | -----: | ----: |
| prune snaps | cron.d      | monthly     | 28     | 3     |
