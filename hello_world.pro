QT += core gui widgets

TEMPLATE = app
TARGET = hello_world
INCLUDEPATH += include

# Source files
SOURCES += main.cpp \
           src/emp_btn.cpp \
           src/add_emp_form.cpp \
           src/EmployeeListDialog.cpp

# Header files
HEADERS += include/emp_btn.h \
           include/add_emp_form.h \
           include/EmployeeListDialog.h \
           include/emp.h

# Output directories for build artifacts
OBJECTS_DIR = o
MOC_DIR = moc
UI_DIR = moc
RCC_DIR = moc
