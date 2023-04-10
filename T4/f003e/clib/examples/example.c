/*{{{  Include */
#include <stdio.h>
#include <string.h>
#include <mathf.h>
#include <math.h>
#include <stdlib.h>
#include <channel.h>
#include <process.h>

#include <cgilib.h>

#include "video.h"
/*}}}*/

Channel *to_cgi, *from_cgi;

/*{{{  palette */
void palette()
{
  int colour = 0;
  int clutloc = 0;

  for( clutloc=0; clutloc<64; clutloc++ )
  {
    colour = clutloc*4;
    fs_setpalette( to_cgi, clutloc,     colour, colour, colour );  /* grey  scale */
    fs_setpalette( to_cgi, clutloc+64,  colour, 0,      0 );       /* red   scale */
    fs_setpalette( to_cgi, clutloc+128, 0,      colour, 0 );       /* green scale */
    fs_setpalette( to_cgi, clutloc+192, 0,      0,      colour );  /* blue  scale */
  }
}
/*}}}*/
/*{{{  boxthere */
int boxThere( int x, int y )
{
  static int xMissing[] = { 0, 1, 0, 0, 1, 0, 7, 7 } ;
  static int yMissing[] = { 0, 0, 1, 7, 7, 6, 6, 7 } ;
  int i;

  for ( i=0; i<8; i++ )
    if ( ( (xMissing [i] == x) && (yMissing [i] == y) ) ||
         ( (yMissing [i] == x) && (xMissing [i] == y) )    )
      return (0);

  return(1);
}
/*}}}*/
/*{{{  logo */
void logo( int x0, int y0, int rad,
           int fg_col, int bg_col )
{
  int boxEdge, holeEdge;
  int xc, yc ;
  int xt, yt ;

  boxEdge = rad/5;
  holeEdge = rad/39;
  xc = (x0 + rad) + 9;
  yc = (y0 + rad) + 9;
  cgi_setfcol( to_cgi, bg_col );
  cgi_fcircle( to_cgi, xc, yc, rad, rad );

  {
    int x0 = (xc - (boxEdge << 2 )) - ((holeEdge * 7) / 2) ;
    int y0 = (yc - (boxEdge << 2 )) - ((holeEdge * 7) / 2) ;
    int x,y;

    for ( x=0; x<8; x++ )
      for ( y=0; y<8; y++ )
        if ( boxThere(x,y) )
        {
          xt= x0 + ( (boxEdge+holeEdge) * x );
          yt= y0 + ( (boxEdge+holeEdge) * y );
          cgi_setfcol( to_cgi, fg_col );
          cgi_frect( to_cgi, xt, yt, xt+boxEdge, yt+boxEdge );
        }
  }

}
/*}}}*/

VTG v = V_1024_768;

int bank = 0;
screen s[1];

int main ()
{
  Process *cgi;
  char error_msg[maxErrString];
  char text1[] = {"inmos ltd"};
  char text2[] = {"IMS-F003  C  CGI  Libraries"};
  int loop1, loop2, errqual;

  to_cgi = ChanAlloc();
  from_cgi = ChanAlloc();

  if ( (to_cgi == NULL) || (from_cgi == NULL) )
  {
    printf( "Failed to allocate channel\n" );
    abort();
  }

  cgi = ProcAlloc( CgiServer, CGI_STACK_SIZE, 2, to_cgi, from_cgi );
  if ( cgi == NULL )
  {
    printf( "Failed to allocate process\n" );
    abort();
  }

  ProcRun( cgi );
  cgi_init( to_cgi );
  fs_openboard( to_cgi, v );

  fs_initscreen( from_cgi, to_cgi, &s[bank], bank );
  printf( "Screen initialised\nraster = 0x%x xsize = %d ysize %d\n",
          (int)(s[bank].raster), s[bank].xsize, s[bank].ysize );
  fs_displaybank( to_cgi, bank );

  palette ();

  cgi_setdrawscreen( to_cgi, s[bank] );
  cgi_setfcol( to_cgi, 127 );
  cgi_cls( to_cgi, s[bank], 255 );

  for ( loop1=0; loop1<256; loop1++ )
  {
    cgi_setfcol( to_cgi, loop1 );
    for ( loop2=0; loop2<4; loop2++ )
      cgi_line( to_cgi, (loop1*4)+loop2, 0, (loop1*4)+loop2, 767 );
  }

  cgi_setdrawmode( to_cgi, PM_COL, RM_XOR, FM_COL );
  for ( loop1=0; loop1<192; loop1++ )
  {
    cgi_setfcol( to_cgi, (4*loop1)/3 );
    for ( loop2=0; loop2<4; loop2++ )
      cgi_line( to_cgi, 0, (loop1*4)+loop2, 1023, (loop1*4)+loop2 );
  }

  cgi_setdrawmode( to_cgi, PM_COL, RM_COL, FM_COL );
  for ( loop1=0; loop1<192; loop1++ )
  {
    cgi_setfcol( to_cgi, (4*loop1)/3 );
    for ( loop2=0; loop2<2; loop2++ )
      cgi_line( to_cgi, 256, 192+(loop1*2)+loop2, 768, 192+(loop1*2)+loop2 );
  }

  cgi_setfcol( to_cgi, 63 );
  cgi_rect( to_cgi, 256, 192, 768, 576 );
  logo( 270, 200, 100, 40, 20 );

  cgi_setfont( from_cgi, to_cgi, font8by8, 
               font_NCHARS, font_FAMW, font_FWPC, font_FLPW );
  cgi_setorient( to_cgi, TX_NORM );
  cgi_chrspace( to_cgi, 10, 0 );

  cgi_setfcol( to_cgi, 127 );
  cgi_setdrawmode( to_cgi, PM_COL, RM_XOR, FM_COL );
  for ( loop1=0; loop1<strlen(text1); loop1++ )
  {
    cgi_chrbegin( to_cgi, 518+(loop1*23), 426 );
    cgi_chrz( to_cgi, text1[loop1], 20, 20 );
  }

  for ( loop1=0; loop1<strlen(text2); loop1++ )
  {
    cgi_chrbegin( to_cgi, 290+(loop1*14), 522 );
    cgi_chrz( to_cgi, text2[loop1], 12, 14 );
  }

  printf( "CGI: errno = %d qual = %d error = %s\n",
          cgi_errstat( from_cgi, to_cgi, error_msg, &errqual ),
          errqual, error_msg ); 

  fs_closeboard( from_cgi, to_cgi );

  cgi_terminate( from_cgi, to_cgi );
}
