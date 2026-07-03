# home file server maintenance
automated zfs scrubs, snapshot pruning, and backups with ntfy notifications. for
cadence, see [schedule](SCHEDULE.md)

## zfs pool
scrubs and snapshot pruning run via cron, with scrub notifications via zed. all
notifications sent with lowered privileges via `runuser`. set up:
```
sudo cp ~/dotfiles/zfs/prune_snapshots.sh /usr/local/sbin
sudo vim /etc/zfs/zed.d/scrub_notify-ntfy.sh  # thin wrapper around notify.sh
sudo vim /etc/zfs/secrets/ntfy  # topic
sudo vim /etc/cron.d/zfs-scrub
sudo vim /etc/cron.d/zfs-prune
```

## backup pipeline
daily db dumps, zfs snapshots, and a 1:1 sync without deletion mirroring from
main file server to backup using user `rsync`
```
cp ~/dotfiles/zfs/.backup.conf.example ~/.backup.conf
vim ~/.backup.conf
crontab -e
```
