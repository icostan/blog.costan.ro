(require 'demo-it)

(defun my-demo-step/show-code ()
  "Helper demo function that displays some source code and
advances the presentation at the same time."
  (demo-it-load-file "post/2019-11-07-emacs-navigation.org")
  (demo-it-presentation-advance))

;; Order the functions and forms for this presentation:
(demo-it-create :advance-mode
		 (demo-it-presentation "post/2019-11-07-emacs-navigation.org")
		 (demo-it-presentation-advance)
		 (demo-it-load-file "../navigation.py" nil nil 120)
		 (clm/toggle-command-log-buffer)
		 (demo-it-presentation-advance)
		 (demo-it-presentation-advance)
		 (demo-it-presentation-advance)
		 (demo-it-presentation-advance)
		 (demo-it-presentation-advance)
		 (demo-it-presentation-advance)
		 (demo-it-presentation-return)
		 (demo-it-load-file "../navigation.py" nil nil 120)
		 (clm/toggle-command-log-buffer)
		 (demo-it-presentation-advance)
		 (demo-it-presentation-advance)
		 (demo-it-presentation-advance)
		 (demo-it-presentation-advance)
		 (demo-it-presentation-return)
		 (demo-it-load-file "~/Repos/linux/net/ipv4/netfilter/nf_reject_ipv4.c" nil nil 150)
		 (clm/toggle-command-log-buffer)
		 (demo-it-presentation-advance)
		 (demo-it-presentation-advance)
		 (demo-it-presentation-advance)
		 (demo-it-presentation-advance)
		 (demo-it-presentation-advance)
		 (demo-it-presentation-advance)
                 demo-it-presentation-return)

(demo-it-start)
