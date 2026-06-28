# backup pipeline
daily db dumps, zfs snapshots, and a 1:1 sync without deletion mirroring from
main file server to backup using user `rsync`
```
cp ~/dotfiles/zfs/.backup.conf.example ~/.backup.conf
vim ~/.backup.conf
crontab -e
```
