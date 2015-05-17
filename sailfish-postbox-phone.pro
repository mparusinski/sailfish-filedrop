# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = sailfish-postbox-phone

CONFIG += sailfishapp

SOURCES += src/sailfish-postbox-phone.cpp

OTHER_FILES += qml/sailfish-postbox-phone.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    qml/pages/SecondPage.qml \
    rpm/sailfish-postbox-phone.changes.in \
    rpm/sailfish-postbox-phone.spec \
    rpm/sailfish-postbox-phone.yaml \
    translations/*.ts \
    sailfish-postbox-phone.desktop

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/sailfish-postbox-phone-de.ts

