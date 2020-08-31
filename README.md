pkgsrc
======

[pkgsrc](https://pkgsrc.org) is a framework for building software for a
variety of UNIX-like systems.

It produces binary packages, which can be managed with tools such as
[pkgin](http://pkgin.net/).

Solaris 10 pkgsrc
-----------------

This fork of pkgsrc includes patches for Solaris 10 on SPARC and x86,
for building 64-bit packages (using `ABI=64`), and for building GCC 7.5
`(lang/gcc7)` with support for the Ada and Go languages. Some testing
has been done with Oracle Developer Studio 12.6, but most testing
has been done so far using the OpenCSW port of GCC 5.5 to bootstrap.

Currently, packages are being rebuilt and tested with GCC 7.5. Older and
newer versions of GCC will be tested and added as well, but the GCC 7
branch appears to be the most stable and likely to generate the best code,
based on the maintainer of this fork's previous testing of GCC 7.4 and 8.4
on NetBSD/sparc64.

### Required packages

- OpenCSW packages for GCC 5.5: `gcc5core` `gcc5g++` (and dependencies).
  Add `gcc5ada` if you want to build GCC from pkgsrc with Ada support.
  [OpenCSW Wikipedia page](https://en.wikipedia.org/wiki/OpenCSW)

### 64-bit bootstrapping

Start out with a `PATH` and `MANPATH` similar to this, for Solaris 10:

`export PATH=/usr/pkg/bin:/usr/pkg/sbin:/usr/pkg/gnu/bin:/opt/csw/bin:/usr/sfw/bin:/usr/bin:/usr/ccs/bin:/usr/sbin:/sbin:/usr/openwin/bin:/usr/dt/bin
export MANPATH=/usr/pkg/man:/usr/share/man:/usr/openwin/man:/usr/dt/man:/opt/csw/man:/usr/sfw/man`

You'll probably want to run `umask 022` if your umask is set to 077.

Then you can use this bootstrap command, as root:

`# CFLAGS="-O2 -pipe -m64" LDFLAGS="-m64" ./bootstrap --abi=64`

If you want to bootstrap with Oracle Studio, try this instead:

`# CC="cc" CXX="CC" CFLAGS="-O -64" LDFLAGS="-64" ./bootstrap --abi=64`

You can make and install packages as your regular user account,
assuming that `/usr/pkgsrc` is owned by your user account, and then
pkgsrc will call "su" automatically when you run bmake install/replace.

You'll definitely want to avoid building Python 3 packages as root, to
avoid the /dev/null symlink being overwritten (see "Known issues" below).

You'll also need to remove the "-m64" from CFLAGS and LDFLAGS before
building GCC from pkgsrc, unless you add `-gcc-multilib`, or the 32-bit
libraries will fail to build. The `pkgtools/cwrappers` wrappers will add
"-m64" automatically and transparently, but pkgsrc currently does not
build and use `cwrappers` if you're using SunPro CC instead of GCC.

### Known issues

- Bootstrapping `lang/gcc7` works, **as long as `security/skey` is not installed.**
  That package was pulled in by `security/openssh` by default, and it installs
  an "sha1.h" header file in `/usr/pkg/include` that doesn't work with Solaris.
  I will fix `security/skey` to not install the conflicting header file.
- For building GCC, you should have `/usr/pkg/gnu/bin` early in your PATH so
  that libgo's configure script can find `objcopy`. I've added a patch to the
  `contrib/compare-debug` script, which compares the `.o` files generated in
  stage2 and stage3, so that it finds the binutils version of `strip` instead of
  Solaris `strip` and doesn't fail due to debug info not being stripped.
- If you don't want to build 32-bit and 64-bit libraries when building GCC
  with `ABI=64`, you can add `-gcc-multilib` to your `PKG_OPTIONS.gcc7`.
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
