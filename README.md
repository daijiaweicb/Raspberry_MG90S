# Setup
Add to '/boot/firmware/config.txt':
```
dtoverlay=pwm-2chan
```
Check with:
```
pinctrl -p
```

# Installation
```bash
cmake .
make
sudo make install
```
