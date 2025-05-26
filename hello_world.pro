QT += core gui widgets

TEMPLATE = app
TARGET = hello_world
INCLUDEPATH += include

# Source files
SOURCES += main.cpp \
           src/main_window.cpp \
           src/emp_btn.cpp \
           src/add_emp_form.cpp \
           src/EmployeeListDialog.cpp \
           src/login_dialog.cpp \
           src/clock.cpp

# Header files
HEADERS += include/main_window.h \
           include/emp_btn.h \
           include/add_emp_form.h \
           include/EmployeeListDialog.h \
           include/emp.h \
           include/login_dialog.h \
           include/clock.h \
           include/gradientStyle.h

# Output directories for build artifacts
OBJECTS_DIR = o
MOC_DIR = moc
UI_DIR = moc
RCC_DIR = moc
