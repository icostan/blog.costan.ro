# blog.costan.ro — Project Summary

A personal technical blog by **Iulian Costan**, built with [Hugo](https://gohugo.io/) and deployed via GitLab Pages at https://blog.costan.ro.

## Stack

| Component     | Technology                        |
|---------------|-----------------------------------|
| Framework     | Hugo (static site generator)      |
| Theme         | beautifulhugo                     |
| CI/CD         | GitLab CI → GitLab Pages          |
| Content       | Markdown with YAML frontmatter    |
| Highlighting  | Pygments                          |

## Content Topics

- **Cryptography** — RSA, ECDSA, Schnorr, BLS, ElGamal signatures
- **Bitcoin / Blockchain** — addresses, transactions, protocols
- **Finance** — options, forex, ATM implied volatility, trading
- **Linux / Emacs** — tools, configuration, workflows
- **Travel** — Inca Trail, geography heat map (Huveragy)

## Directory Structure

```
blog.costan.ro/
├── config.toml        # Hugo configuration (menus, author, theme)
├── content/
│   ├── post/          # Blog posts (Markdown)
│   └── page/          # Static pages (About, Forex, etc.)
├── layouts/           # Custom templates and shortcodes
├── static/            # Images, CSS, certificates
├── themes/
│   ├── beautifulhugo/ # Primary theme
│   └── Lanyon/        # Legacy theme
└── .gitlab-ci.yml     # Build & deploy pipeline
```

## Build & Deploy

```bash
hugo server   # Local preview at localhost:1313/
hugo          # Build static site to public/
```

Deployment is automated: pushing to `master` triggers the GitLab CI pipeline, which builds the site and publishes it to GitLab Pages.
