```bash

# compile  
make lily58:ll14m4n
# or
qmk compile -kb lily58 -km ll14m4n


# flash
make lily58:ll14m4n:avrdude-split-right
make lily58:ll14m4n:avrdude-split-right



# miryoku
make lily58:manna-harbour_miryoku:flash MIRYOKU_CLIPBOARD=MAC MIRYOKU_NAV=INVERTEDT


qmk compile -c -kb lily58 -km manna-harbour_miryoku -e MIRYOKU_CLIPBOARD=MAC -e MIRYOKU_NAV=INVERTEDT


```



 


