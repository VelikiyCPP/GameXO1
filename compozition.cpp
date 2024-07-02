
#include <iostream>
#include <memory>

//Демонстрация кода по С++ на ранг начинающий маг по ООП

/*
1. базовое заклинание
class Spell {
public:
    virtual void activate() noexcept {
        std::cout << "Spell activated" << std::endl;
    }
};

int main() {
    Spell spell;
    spell.activate();
    return 0;
}
*/

/*
2. Заклинание  наследования
class Spell {
public:
    virtual void activate() noexcept {
        std::cout << "Spell activated" << std::endl;
    }
};

class FireSpell : public Spell {
public:
    void activate() noexcept override {
        std::cout << "FireSpell activated" << std::endl;
    }
};


int main() {
    Spell spell;
    Spell* fireSpell = new FireSpell; // Полиморфизм
    spell.activate();
    fireSpell->activate();

    delete fireSpell;
    return 0;
}
*/

/*
3. Заклинание полиморфизма

class Spell {
public:
    virtual void activate() noexcept {
        std::cout << "Spell activated" << std::endl;
    }

    void castSpell(Spell& spell){
        spell.activate();
    }
};

class FireSpell : public Spell {
public:
    void activate() noexcept override {
        std::cout << "FireSpell activated" << std::endl;
    }
};

class WindSpell : public Spell {
public:
    void activate() noexcept override {
        std::cout << "WindSpell activated" << std::endl;
    }
};

int main() {
    Spell spell;
    Spell* fireSpell = new FireSpell;

    spell.castSpell(*fireSpell);

    delete fireSpell;
    return 0;
}
*/

/*
4. Виртуальные функции позволяют производным классам от конкретного класса, унаследовать функцию и изменить её по своему усмотрению для себя, например анимал, собака унаследует от анимал функцию пустую, сделает гав гав, когда кошка мяу мяу
*/

/*
5. Чистые виртуальные функции в отличии от простых функции, содержатся в абстрактных классах или интерфейсах, а ещё нету у них реализации, служа реализацией для производных классов
создаются [attribute] virtual type function(argument...) attribut... = 0;
*/

/*
6.  Система  RTTI конечно я её не проходил, но конструкторы и дееструкторы контролируют саму жизнь объекта, что как раз относится к термину RTTI
class C {
    C() {} // конструктор (создание)
    ~C() {} // дееструктор (до системного уничтожения пока есть у нас последний контроль, чтобы грамотно уничтожить объект)
};
*/

/*
7-8. Умные указатели unique_ptr позволяет например ссылаться на объект и только он, если кто-то унаследует из него или отберёт, например unique_ptr то сразу станет null, но если сделать *ptr то скорее всего он не сомжет это отследить
ведь он не контролирует процесс, указатель не заметно будет ссылаться на объект, но это уже как взлом пошёл против правил, поэтому нужно с него грамотно брать и дать знать что пересылались на его объект.
когда shared_ptr позволяет иметь более 1 указателя умного или обычных но нужно дать ему это знать что они ссылаются, лучше забыть про простые указатели по возможности и брать умные и когда его счётчик будет равен 0, данные уничтожатся, когда unqiue_ptr уничтожается если выйдет из поле видемости, но
shared_ptr так же делает, просто там иначе delete shared1...9, вызов я предпологаюа общего конструктора, знать не могу я сдаю эказамен на начинающего мага по ООП
*/

/*
Тут будет пример с умными указателями и композицией
class Spell {
public:
    virtual void activate() noexcept {
        std::cout << "Spell activated" << std::endl;
    }
};

class FireSpell : public Spell {
public:
    void activate() noexcept override {
        std::cout << "FireSpell activated" << std::endl;
    }
};

class Wizard {
public:
    Wizard(const std::string& name = "(secret)", std::unique_ptr<Spell> spell = std::make_unique<Spell>()) : m_name(name), m_spell_magic(std::move(spell)) {
        std::cout << "Wizard created " << m_name << std::endl;
    }

    void cast() {
        std::cout << "Wizard name is (" << m_name << ") activate magic is ";
        m_spell_magic->activate(); std::cout << std::endl;
    }

    ~Wizard() {
        std::cout << "Wizard die" << std::endl;
    }
private:
    std::string m_name;
    std::unique_ptr<Spell> m_spell_magic;
};

int main() {
    std::unique_ptr<Spell> spell = std::make_unique<Spell>();
    std::unique_ptr<Spell> fireSpell = std::make_unique<FireSpell>();

    spell->activate();
    fireSpell->activate();

    Wizard wizard("Merlin", std::move(spell));
    Wizard wizard2("Chaos", std::move(fireSpell));
    wizard.cast();
    wizard2.cast();

    std::shared_ptr<Spell> spellShared = std::move(spell);
    std::shared_ptr<Spell> fireShared = std::move(fireSpell);

    return 0;
}
*/