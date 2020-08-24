pkgsrc
======

[pkgsrc](https://pkgsrc.org) is a framework for building software for a
variety of UNIX-like systems.

It produces binary packages, which can be managed with tools such as
[pkgin](http://pkgin.net/).

SPARC Solaris 10
----------------

This fork of pkgsrc has local changes for Solaris 10 on SPARC, and for
building 64-bit packages (`ABI=64`). I will add more notes later. -jhamby

### Required packages

- OpenCSW packages (**TODO: add list of needed bootstrap packages**).
  [OpenCSW Wikipedia page](https://en.wikipedia.org/wiki/OpenCSW)

### Known issues

- It's not yet possible to bootstrap GCC or newer (with `ABI=64`).
  I hope to support at least `lang/gcc5`, `lang/gcc6`, and `lang/gcc7`.
- SunPro compiler can't find header files in same directory as source files,
  when there is a `#line` directive in the source code (e.g. generated code).
  I worked around this bug in bootstrapping by adding `"-I."` to `CPPFLAGS`.
- `devel/libffi` build failure using SunPro compiler.
- You must rebuild `devel/libtool-base` whenever switching compilers, or
  new builds using GNU libtool will use the wrong compiler flags.
- You must add `PKG_OPTIONS.openssh=-editline` to `mk.conf` for now to build
  security/openssh, as devel/editline is currently broken.
- **`textproc/asciidoc` & `devel/meson` overwrite `/dev/null` during builds.**
  `/dev/null` is being replaced with an empty file, causing install to fail.
  I believe this is a Python 3 issue related to `/dev/null` being a symlink.
- `sysutils/smartmontools` builds but doesn't return all of the SMART info.
  The version of smartmontools in OpenCSW doesn't have this problem.

Bootstrapping
-------------

To use pkgsrc on operating systems other than NetBSD, you first need to
bootstrap:

	cd pkgsrc/bootstrap
	./bootstrap

Note that this is only for the most simple case, using pkgsrc's defaults.

Please consult `bootstrap/README` and `bootstrap/README.OS` for detailed
information about bootstrapping.

Building packages
-----------------

	cd pkgsrc/category/package-name
	$PREFIX/bin/bmake install

Where `$PREFIX` is where you've chosen to install packages
(typically `/usr/pkg`)

On NetBSD, `bmake` is simply the built-in `make` tool.

To build packages in bulk, tools such as `pkgtools/pbulk` and
`pkgtools/pkg_comp` can be used.

Troubleshooting
---------------

- Join the community IRC channel [#pkgsrc @ freenode](https://webchat.freenode.net/?channels=#pkgsrc).
- Subscribe to the [pkgsrc-users](https://netbsd.org/mailinglists/#pkgsrc-users) mailing list
- Send bugs and patches [via web form](https://www.netbsd.org/cgi-bin/sendpr.cgi?gndb=netbsd) (use the `pkg` category).

Latest sources
--------------

To fetch the main CVS repository:

	cvs -d anoncvs@anoncvs.NetBSD.org:/cvsroot checkout -P pkgsrc

To work in the Git mirror, which is updated every few hours from CVS:

	git clone https://github.com/NetBSD/pkgsrc.git

Additional links
----------------

- [The pkgsrc guide](https://www.netbsd.org/docs/pkgsrc/)
- [pkgsrc in the NetBSD Wiki](https://wiki.netbsd.org/pkgsrc/)
- [Searchable index of packages in pkgsrc](http://pkgsrc.se/)
- [pkgsrc-wip](https://pkgsrc.org/wip/) - a project to get more people actively involved with creating packages for pkgsrc
- [pkgsrc on Twitter](https://twitter.com/pkgsrc)
- [pkgsrcCon](https://pkgsrc.org/pkgsrcCon)
