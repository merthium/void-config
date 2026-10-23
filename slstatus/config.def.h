/* config.h — slstatus */
#include <fcntl.h>
#include <sys/file.h>
#include <unistd.h>

#define MAXLEN 1024
const unsigned int interval = 2000;
static const char unknown_str[] = "n/a";
#define R "^d^"

/*
 * eyes.nvim dark. Durum metni kendi status2d renklerini kullandigi icin
 * dwm paletiyle burada da eslestirilir.
 */
#define FG "^c#a0a0a0^"
#define ICE "^c#a0a0a0^"
#define CREAM "^c#a0a0a0^"
#define LAVENDER "^c#a0a0a0^"
#define MINT "^c#a0a0a0^"
#define WARN "^c#a0a0a0^"
#define SEP "^c#606060^ | " R

/* Two-pixel strokes centered at y=12 in the 24px bar. */
#define BAT_ICON "^r0,6,16,2r0,16,16,2r0,8,2,8r14,8,2,8r16,10,2,4r4,10,3,4r9,10,3,4f22^"
#define CLOCK_ICON "^r4,4,10,2r2,6,2,2r14,6,2,2r0,8,2,8r16,8,2,8r2,16,2,2r14,16,2,2r4,18,10,2r8,8,2,6r10,12,4,2f22^"
#define CUP_ICON "^r4,2,2,4r10,2,2,4r0,8,14,2r0,10,2,6r12,10,2,6r2,16,10,2r14,8,4,2r16,10,2,4r14,14,4,2r0,20,16,2f22^"

static const struct arg args[] = {
    {battery_perc, ICE BAT_ICON FG "%s%%" R SEP, "BAT0"},
    {datetime,     CREAM CLOCK_ICON FG "%s" R SEP, "%H:%M"},
};
