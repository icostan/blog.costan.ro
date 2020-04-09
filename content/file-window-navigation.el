(require 'demo-it)

(defun open-4-files ()
  (demo-it-load-file "Kbuild")
  (split-window-below)
  (demo-it-load-file "Makefile" :none nil nil)
  (demo-it-load-file "2020-03-24-write-linux-kernel-module.org")
  (split-window-below)
  (demo-it-load-file "hello.c" :none nil nil))

(defun open-2-files ()
  (demo-it-load-file "Makefile")
  (split-window-below)
  (demo-it-load-file "Kbuild" :none nil nil))

;; Order the functions and forms for this presentation:
(demo-it-create :advance-mode
		 (demo-it-presentation "post/2020-04-04-emacs-file-window-buffer-navigation.org")

		 ;; intro
		 (demo-it-presentation-return)

		 ;; frames
		 (clm/toggle-command-log-buffer)
		 (demo-it-presentation-advance)
		 (demo-it-presentation-advance)
		 (demo-it-presentation-return)

		 ;; files
		 (demo-it-presentation-advance)
		 open-2-files
		 (demo-it-presentation-return)
		 open-2-files
		 (demo-it-presentation-return)
		 (demo-it-presentation-return)

		 ;; windows
		 (demo-it-presentation-advance)
		 (demo-it-load-file "Makefile")
		 (demo-it-presentation-return)
		 open-4-files
		 (demo-it-presentation-return)
		 open-4-files
		 (demo-it-presentation-return)
		 (demo-it-load-file "world.c")
		 (demo-it-presentation-return)

		 ;; buffers
		 (demo-it-presentation-advance)
		 open-2-files
		 (demo-it-presentation-return)
		 open-2-files
		 (demo-it-presentation-return)

		 ;; footer
		 (demo-it-presentation-advance))

(demo-it-start)
