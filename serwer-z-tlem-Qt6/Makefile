

__start__: ./serwer_graficzny
	rm -f core*; ulimit -c unlimited;\
          export LD_LIBRARY_PATH="`/bin/pwd`/libQGLViewer/QGLViewer:$LD_LIBRARY_PATH";\
          ./serwer_graficzny


./serwer_graficzny:
	@if which qmake6 > /dev/null; then export QT=6;\
             elif which qmake > /dev/null; then export QT=5;\
             else echo -e "\n Brak programu qmake lub qmake6\n"; exit 1; fi;\
             make -f Makefile.exec QT=$${QT}


clean:
	cd serwer_zrodla; make -f Makefile.server clean QT=6
	cd libQGLViewer; make clean
	rm -f .qmake.stash


clean_all: clean
	cd serwer_zrodla; make -f Makefile.server cleantotally QT=6
	rm -f serwer_graficzny
	rm -f libQGLViewer/QGLViewer/libQGLViewer-qt6.*
