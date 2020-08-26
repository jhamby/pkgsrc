pkgsrc
======

[pkgsrc](https://pkgsrc.org) is a framework for building software for a
variety of UNIX-like systems.

It produces binary packages, which can be managed with tools such as
[pkgin](http://pkgin.net/).

SPARC Solaris 10
----------------

This fork of pkgsrc includes changes to support Solaris 10 on SPARC,
building 64-bit packages (using `ABI=64`), and building GCC 5.5
`(lang/gcc5)` with support for the Ada and Go languages. Some testing
has been done with Oracle Developer Studio 12.6 as well.

As you read this, the GCC 5.5 port is being rebuilt and tested, and
then new versions of GCC will be bootstrapped for Solaris 10, starting
with `(lang/gcc6)` and proceeding until GCC 10.2, if possible.

### Required packages

- OpenCSW packages (**TODO: add list of needed bootstrap packages**).
  [OpenCSW Wikipedia page](https://en.wikipedia.org/wiki/OpenCSW)

### Known issues

- Bootstrapping `lang/gcc5` works, **as long as `security/skey` is not installed.**
  That package was pulled in by `security/openssh` by default, and it installs
  an "sha1.h" header file in /usr/pkg/include that doesn't work with Solaris.
  I will fix `security/skey` to not install the conflicting header file.
- If you want to build GCC with Go support, you must have `/usr/pkg/gnu/bin`
  in your PATH so that libgo's configure script can find `objcopy`. libgo
  should respect the value of OBJCOPY passed in the environment to the top-level
  `configure` script, but the value doesn't seem to get passed through.
  The `objcopy` command is also hardcoded in GCC 5's `gcc/gcc.c` source file.
- If you don't want to build 32-bit and 64-bit libraries when building GCC
  with `ABI=64`, you can add `-gcc-multilib` to your `PKG_OPTIONS.gcc5`.
- SunPro compiler can't find header files in same directory as source files,
  when there is a `#line` directive in the source code (e.g. generated code).
  I worked around this bug in bootstrapping by adding `"-I."` to `CPPFLAGS`.
- `devel/libffi` build failure using SunPro compiler.
- You must rebuild `devel/libtool-base` whenever switching compilers, or
  new builds using GNU libtool will use the wrong compiler flags.
- You must add `PKG_OPTIONS.openssh=-editline` to `mk.conf` for now to build
  security/openssh, as devel/editline is currently broken.
- **Some packages using Python 3, e.g. `textproc/asciidoc` & `devel/ninja-build`,
  overwrite `/dev/null` during builds when run as root.**
  `/dev/null` is being replaced with an empty file, causing install to fail.
  I believe this is a Python 3 issue related to `/dev/null` being a symlink.
  *As a workaround, you can build the packages as non-root, then install as root.*
- `sysutils/smartmontools` builds but doesn't return all of the SMART info.
  The version of smartmontools in OpenCSW doesn't have this problem.
- The `USE_FEATURES` options that build libnbcompat don't work when the package
  is or includes a shared library, because libnbcompat isn't built with `-fPIC -DPIC`
  (or `-KPIC -DPIC` for SunPro C). Fixing this will unblock many currently-broken
  packages that use, e.g. `strnlen()`.

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
