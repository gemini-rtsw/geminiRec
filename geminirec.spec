%define _prefix /gem_base/epics/support
%define name geminiRec
%define repository gemdev
%define debug_package %{nil}
%define arch %(uname -m)
%define checkout %(git log --pretty=format:'%h' -n 1) 

#These global defines are added to prevent stripping
# symbols on vxWorks cross-compiled code
# Getting 'strip' to work is probably only needed for
# building a related debug sub-package
#
# But this prevents all the strip warnings
# mrippa 20120202
%global _enable_debug_package 0
%global debug_package %{nil}
%global __os_install_post /usr/lib/rpm/brp-compress %{nil}

Summary: %{name} Package, a module for EPICS base
Name: %{name}
Version: 4.1.13
Release: 0%{?dist}
License: EPICS Open License
Group: Applications/Engineering
Source0: %{name}-%{version}.tar.gz
ExclusiveArch: %{arch}
Prefix: %{_prefix}
## You may specify dependencies here
BuildRequires: epics-base-devel re2c gemini-ade
Requires: epics-base
## Switch dependency checking off
# AutoReqProv: no

%description
This is the module %{name}.

## If you want to have a devel-package to be generated uncomment the following:
%package devel
Summary: %{name}-devel Package
Group: Development/Gemini
Requires: %{name}
%description devel
This is the module %{name}.

%prep
%setup -q 

%build
make distclean uninstall
make

%install
export DONT_STRIP=1
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/%{_prefix}/%{name}
cp -r dbd $RPM_BUILD_ROOT/%{_prefix}/%{name}
cp -r db $RPM_BUILD_ROOT/%{_prefix}/%{name}
#cp -r bin $RPM_BUILD_ROOT/%{_prefix}/%{name}
cp -r lib $RPM_BUILD_ROOT/%{_prefix}/%{name}
cp -r include $RPM_BUILD_ROOT/%{_prefix}/%{name}
cp -r configure $RPM_BUILD_ROOT/%{_prefix}/%{name}
find $RPM_BUILD_ROOT/%{_prefix}/%{name}/configure -name ".git" -exec rm -rf {} \;


%postun
if [ "$1" = "0" ]; then
	rm -rf %{_prefix}/%{name}
fi


%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root)
#   /%{_prefix}/%{name}/bin
   /%{_prefix}/%{name}/lib

%files devel
%defattr(-,root,root)
   /%{_prefix}/%{name}/dbd
   /%{_prefix}/%{name}/db
   /%{_prefix}/%{name}/include
   /%{_prefix}/%{name}/configure

%changelog
* Tue Dec 30 2025 Matt Rippa <matt.rippa@noirlab.edu> 4.1.13-4
- SYSCO-745: Add TDCT eapply20 support
- rebuilding rpm using gem-ci master branch
- #26: prepare unstable/2024q3 release
- Update to unstable/2024q1
- Update gem-ci to unstable/2024q1
- update gem-ci to master branch
- switch to new gem-ci unstable/2023q3 and create branch
  unstable/2023q3-ntpd_ostime
- switch to new gem-ci and create unstable/2023q3-ntpd release
- Workaround to implement mechanism menus
- create unstable/2023q2 branch/release
- gem-ci module updated
- Building to unstable/2023q1-tr2
- Building to unstable/2023q1-tr1
- Building for unstable/2022q4
- Building for unstable/2022q4
- Building for unstable/2022q4
- Added newer version of gem-ci, relates to issue #21
- gem-init-project.sh
- Rebuild for epics-base unstable/2022q1-tr4. Releted to nsf-
  noirlab/gemini/rtsw/epics-base/epics-base#10.
- This version fix the apply Record problem to count the links properly #17
- Fix problem with types. Use dbValueSize instead of sizeofTypes
- unstable/2022q1-tr1: gem-init-project
- BASE_CONTAINER to epics-base/unstable/2022q1-tr1
- Starting 2022q1 and gem-ci stable/2021q4
- Improvement of issue #9
- Update gem-ci and set branch to stable/2021q4
- Changed base container to testing maturity level for a test push
- Updated base container to registry.gitlab.com/nsf-
  noirlab/gemini/rtsw/iocs/softtcs_mk/unstable/containerization:latest
- ADE2 gem-init-project.sh
- Another releasers.conf change
- Yet another fix to release.conf
- typo in release.conf
- Updated repo location in .tito/releasers.conf
- Changes made by gem-init-project.sh
- Epics7 compilation without warning, resolving the following issues: #1 #3 #4
  #5 #6 #7 #8 #9
- fixed a debug message
- test printout to track debug version
- Updated release
- Test fix

* Thu Oct 08 2020 fkraemer <fkraemer@gemini.edu> 4.1.13-2
- applied tito configuration for new yum repositories
- applied new version/release scheme
* Fri Aug 28 2020 Felix Kraemer <fkraemer@gemini.edu> 3.15.8-4.1.13.202008282139560fda4
- Adjustments to import configuration from configure/RELEASE.local for testing
  puposes (fkraemer@gemini.edu)
- Release tag enriched with hour and minute (%%H%%M) to be able to build
  several RPMs a day without messing up the repo (fkraemer@gemini.edu)

* Wed Jul 29 2020 fkraemer <fkraemer@gemini.edu> 3.15.8-4.1.13.20200729d835ed7
- added db directory to be copied/installed (fkraemer@gemini.edu)

* Sun Jul 26 2020 fkraemer <fkraemer@gemini.edu> 3.15.8-4.1.13.20200726ff76345
- RPM build possible
- no bin dir, so removed from specfile (fkraemer@gemini.edu)
- added gemini-ade dependency (fkraemer@gemini.edu)

* Wed Jul 22 2020 fkraemer <fkraemer@gemini.edu> 3.15.8-4.1.13.20200722b932e58
- fixed a merge conflict (fkraemer@gemini.edu)

* Wed Jul 22 2020 fkraemer <fkraemer@gemini.edu> 3.15.8-4.1.13.202007220c32b86
- new package built with tito

* Wed Jul 22 2020 fkraemer <fkraemer@gemini.edu> 3.15.8-4.1.13.20200722a1645a1
- new package built with tito

* Wed Jul 22 2020 fkraemer <fkraemer@gemini.edu> 3.15.8-4.1.13.2020072238eb7bd
- new package built with tito

* Wed Jul 22 2020 fkraemer <fkraemer@gemini.edu> 3.15.8-4.1.13.2020072286a4352
- new package built with tito
