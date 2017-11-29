#ifndef DISASSEMBLERTEST_H
#define DISASSEMBLERTEST_H

#include <map>
#include <functional>
#include <QStringList>
#include "redasm/disassembler/disassembler.h"

class DisassemblerTest
{
    private:
        typedef std::function<void(REDasm::Disassembler*)> TestCallback;
        typedef std::map<std::string, TestCallback> TestList;
        typedef std::pair<std::string, TestCallback> TestItem;

    public:
        DisassemblerTest();
        void runTests();

    private:
        std::string replaceAll(std::string str, const std::string& from, const std::string& to);
        QByteArray readFile(const QString& file) const;
        void runTest(QByteArray &data, TestCallback testcallback);

    private:
        void testVBEvents(REDasm::Disassembler* disassembler, const std::map<address_t, std::string>& vbevents);

    private: // Tests
        void testCavia(REDasm::Disassembler* disassembler);
        void testCM01(REDasm::Disassembler* disassembler);
        void testSCrack(REDasm::Disassembler* disassembler);
        void testVB5CrackMe(REDasm::Disassembler* disassembler);

    private:
        TestList _tests;
};

#endif // DISASSEMBLERTEST_H