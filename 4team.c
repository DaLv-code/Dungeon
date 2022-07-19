            Start_Player[classCount].DP += (5 * DropLv);
            break;
        }
        if (EquipmentState[2][5] = DropLv)
        {
            EquipmentState[3][5] = DropLv;
            classCount = 3;
            Start_Player[classCount].DP += (5 * DropLv);
            break;
        }
        if (EquipmentState[1][5] = DropLv)
        {
            EquipmentState[2][5] = DropLv;
            classCount = 2;
            Start_Player[classCount].DP += (5 * DropLv);
            break;
        }
        if (EquipmentState[0][5] = DropLv)
        {
            EquipmentState[1][5] = DropLv;
            classCount = 1;
            Start_Player[classCount].DP += (5 * DropLv);
            break;
        }
        EquipmentState[0][5] = DropLv;
        classCount = 0;
        Start_Player[classCount].DP += (5 * DropLv);
        break;
    case 19: //천망토
        if (EquipmentState[5][5] == DropLv)
        {
            printf("이미 착용하고 있는 장비와 효과가 같습니다!\n");
            return;
        }
        if (EquipmentState[4][5] = DropLv)
        {
            EquipmentState[5][5] = DropLv;
            classCount = 5;
            Start_Player[classCount].DP += (5 * DropLv);
            break;
        }
        if (EquipmentState[3][5] = DropLv)
        {
            EquipmentState[4][5] = DropLv;
            classCount = 4;
            Start_Player[classCount].DP += (5 * DropLv);
            break;
        }
        if (EquipmentState[2][5] = DropLv)
        {
            EquipmentState[3][5] = DropLv;
            classCount = 3;
            Start_Player[classCount].DP += (5 * DropLv);
            break;
        }
        if (EquipmentState[1][5] = DropLv)
        {
            EquipmentState[2][5] = DropLv;
            classCount = 2;
            Start_Player[classCount].DP += (5 * DropLv);
            break;
        }
        if (EquipmentState[0][5] = DropLv)
        {
            EquipmentState[1][5] = DropLv;
            classCount = 1;
            Start_Player[classCount].DP += (5 * DropLv);
            break;
        }
        EquipmentState[0][5] = DropLv;
        classCount = 0;
        Start_Player[classCount].DP += (5 * DropLv);
        break;
    case 20: //사슬장갑
        if (EquipmentState[0][6] == DropLv)
        {
            printf("이미 착용하고 있는 장비와 효과가 같습니다!\n");
            return;
        }
        EquipmentState[0][6] = DropLv;
        classCount = 0;
        Start_Player[classCount].DP += (5 * DropLv);
        break;
    case 21: //천장갑
        if (EquipmentState[2][6] == DropLv)
        {
            printf("이미 착용하고 있는 장비와 효과가 같습니다!\n");
            return;
        }
        if (EquipmentState[1][6] == DropLv)
        {
            EquipmentState[2][6] = DropLv;
            classCount = 2;
            Start_Player[classCount].DP += (5 * DropLv);
            break;
        }
        EquipmentState[1][6] = DropLv;
        classCount = 1;
        Start_Player[classCount].DP += (5 * DropLv);
        break;
    case 22: //가죽장갑
        if (EquipmentState[5][6] == DropLv)
        {
            printf("이미 착용하고 있는 장비와 효과가 같습니다!\n");
            return;
        }
        if (EquipmentState[4][6] == DropLv)
        {
            EquipmentState[5][6] = DropLv;
            classCount = 5;
            Start_Player[classCount].DP += (5 * DropLv);
            break;
        }
        if (EquipmentState[3][6] == DropLv)
        {
            EquipmentState[4][6] = DropLv;
            classCount = 4;
            Start_Player[classCount].DP += (5 * DropLv);
            break;
        }
        EquipmentState[3][6] = DropLv;
        classCount = 3;
        Start_Player[classCount].DP += (5 * DropLv);
        break;
    default:
        break;
    }

    printf("%s가 ", Start_Player[classCount].class_name);
    if (DropLv == 1)
        printf("%s를 획득하였습니다!\n", (EquipmentListLv1)[randomDrop]);
    else if (DropLv == 2)
        printf("%s를 획득하였습니다!\n", (EquipmentListLv2)[randomDrop]);
    else if (DropLv == 3)
        printf("%s를 획득하였습니다!\n", (EquipmentListLv3)[randomDrop]);
}

void itemDrop(int *itemList, int DropLv)
{
    int DropLv1[3] = {0, 3, 6}, DropLv2[3] = {1, 4, 7}, DropLv3[3] = {2, 5, 8};
    int itemCount = rand() % 3 + 1;
    int DropCount;
    int SpecialItemDrop = rand() % 10;
    int SpecialItemCount = 0;

    if (SpecialItemDrop == 1)
    {
        itemList[9]++; // 10퍼센트 확률로 부활의 깃털 획득
        SpecialItemCount++;
    }
    else if (SpecialItemDrop == 0)
    {
        itemList[10]++; // 10퍼센트 확률로 텐트 획득
        SpecialItemCount++;
    }

    printf("%d개의 아이템 획득!\n", itemCount + SpecialItemCount);

    for (int i = 0; i < itemCount; i++)
    {
        if (DropLv == 1)
        {
            DropCount = rand() % 3;
            itemList[DropLv1[DropCount]]++;
        }
        else if (DropLv == 2)
        {
            DropCount = rand() % 3;
            itemList[DropLv2[DropCount]]++;
        }
        else if (DropLv == 3)
        {
            DropCount = rand() % 3;
            itemList[DropLv3[DropCount]]++;
        }
    }
}

void itemUse(int *itemList, Class *Start_Player, int person)
{
    int itemSelect;
    void (*itemArr[5])(int, Class *, int);
    itemArr[0] = HpPotion;
    itemArr[1] = MpPotion;
    itemArr[2] = AllPotion;
    itemArr[3] = Resurrection;
    itemArr[4] = Tent;

    while (1)
    {
        printf("어떤 아이템을 사용하시겠습니까? : ");
        scanf(" %d", &itemSelect);

        if (itemList[itemSelect] < 1)
        {
            printf("사용가능한 아이템이 없습니다!\n");
            sleep(1);
            return;
        }
        else
            itemList[itemSelect]--;

        if (itemSelect >= 0 && itemSelect < 9)
            itemArr[itemSelect / 3](itemSelect % 3 + 1, Start_Player, person);
        else if (itemSelect == 9)
            itemArr[3](itemSelect % 3 + 1, Start_Player, person);
        else if (itemSelect == 10)
            itemArr[4](itemSelect % 3 + 1, Start_Player, person);

        return;
    }
}

void HpPotion(int DropLv, Class *Start_Player, int person) // HP포션
{
    if (DropLv == 1)
    {
        Start_Player[person].NowHp += Start_Player[person].MaxHp / 4;
        printf("초심자용 HP포션을 사용하였습니다!\n");
    }
    else if (DropLv == 2)
    {
        Start_Player[person].NowHp += Start_Player[person].MaxHp / 2;
        printf("중급자용 HP포션을 사용하였습니다!\n");
    }
    else if (DropLv == 3)
    {
        Start_Player[person].NowHp += Start_Player[person].MaxHp;
        printf("상급자용 HP포션을 사용하였습니다!\n");
    }

    if (Start_Player[person].NowHp > Start_Player[person].MaxHp)
        Start_Player[person].NowHp = Start_Player[person].MaxHp;
}

void MpPotion(int DropLv, Class *Start_Player, int person) // MP포션
{
    if (DropLv == 1)
    {
        Start_Player[person].NowMp += Start_Player[person].MaxMp / 4;
        printf("초심자용 MP포션을 사용하였습니다!\n");
    }
    else if (DropLv == 2)
    {
        Start_Player[person].NowMp += Start_Player[person].MaxMp / 2;
        printf("중급자용 MP포션을 사용하였습니다!\n");
    }
    else if (DropLv == 3)
    {
        Start_Player[person].NowMp += Start_Player[person].MaxMp;
        printf("상급자용 MP포션을 사용하였습니다!\n");
    }

    if (Start_Player[person].NowMp > Start_Player[person].MaxMp)
        Start_Player[person].NowMp = Start_Player[person].MaxMp;
}

void AllPotion(int DropLv, Class *Start_Player, int person) // ALL포션
{
    if (DropLv == 1)
    {
        Start_Player[person].NowHp += Start_Player[person].MaxHp / 4;
        Start_Player[person].NowMp += Start_Player[person].MaxMp / 4;
        printf("초심자용 ALL포션을 사용하였습니다!\n");
    }
    else if (DropLv == 2)
    {
        Start_Player[person].NowHp += Start_Player[person].MaxHp / 2;
        Start_Player[person].NowMp += Start_Player[person].MaxMp / 2;
        printf("중급자용 ALL포션을 사용하였습니다!\n");
    }
    else if (DropLv == 3)
    {
        Start_Player[person].NowHp += Start_Player[person].MaxHp;
        Start_Player[person].NowMp += Start_Player[person].MaxMp;
        printf("상급자용 ALL포션을 사용하였습니다!\n");
    }

    if (Start_Player[person].NowHp > Start_Player[person].MaxHp)
        Start_Player[person].NowHp = Start_Player[person].MaxHp;

    if (Start_Player[person].NowMp > Start_Player[person].MaxMp)
        Start_Player[person].NowMp = Start_Player[person].MaxMp;
}

void Resurrection(int DropLv, Class *Start_Player, int person)
{
    int select;
    printf("누구에게 부활의 깃털을 사용하겠습니까? 0:%s  1:%s  2:%s  3:%s  4:%s", Start_Player[0].name, Start_Player[1].name, Start_Player[2].name, Start_Player[3].name, Start_Player[4].name);
    scanf("%d", &select);
    if (Start_Player[select].NowHp == 0)
    {
        printf("부활의 깃털을 사용하였습니다!\n");
        Start_Player[select].NowHp = Start_Player[select].MaxHp;
    }
    else
    {
        printf("부활의 깃털은 쓰러진 클래스에게 사용할 수 있습니다!\n");
        Resurrection(DropLv, Start_Player, person);
    }
}

void Tent(int DropLv, Class *Start_Player, int person)
{
    printf("텐트를 사용하여 잠을 잡니다...zz\n");
    for (int i = 0; i < 5; i++)
        Start_Player[i].NowHp = Start_Player[i].MaxHp;
}

void battleUI(char **monster, char **playericon, Class *Start_Player, int *mobHp, int *itemList)
{
    for (int i = 0; i < 5; i++)
    {
        if (Start_Player[i].NowHp < 0)
            Start_Player[i].NowHp = 0;
    }
    for (int i = 0; i < 10; i++)
    {
        if (*(mobHp + i) < 0)
            *(mobHp + i) = 0;
    }
    printf(" ▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃\n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏              %s                %s                 %s                %s                 %s                                            \n", monster[0], monster[1], monster[2], monster[3], monster[4]);
    printf(" ▏                %d              %d               %d              %d                %d                                                 \n", *mobHp, *(mobHp + 1), *(mobHp + 2), *(mobHp + 3), *(mobHp + 4));
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                       \n");
    printf(" ▏              %s                 %s                 %s                %s                %s                                             \n", monster[5], monster[6], monster[7], monster[8], monster[9]);
    printf(" ▏                %d               %d                %d                %d            %d                                                 \n", *(mobHp + 5), *(mobHp + 6), *(mobHp + 7), *(mobHp + 8), *(mobHp + 9));
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                       \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏               %s                  %s                  %s                 %s                %s                                            \n", (playericon[0]), *(playericon + 1), *(playericon + 2), *(playericon + 3), *(playericon + 4));
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃  \n");
    printf(" ▏          %s                    %s                    %s                   %s                    %s           \n", Start_Player[0].name, Start_Player[1].name, Start_Player[2].name, Start_Player[3].name, Start_Player[4].name);
    printf(" ▏          %s                    %s                    %s                   %s                    %s           \n", Start_Player[0].class_name, Start_Player[1].class_name, Start_Player[2].class_name, Start_Player[3].class_name, Start_Player[4].class_name);
    printf(" ▏         HP\\ %d                HP\\ %d               HP\\ %d              HP\\ %d               HP\\ %d           \n", Start_Player[0].NowHp, Start_Player[1].NowHp, Start_Player[2].NowHp, Start_Player[3].NowHp, Start_Player[4].NowHp);
    printf(" ▏         MP\\ %d                MP\\ %d               MP\\ %d              MP\\ %d               MP\\ %d           \n", Start_Player[0].NowMp, Start_Player[1].NowMp, Start_Player[2].NowMp, Start_Player[3].NowMp, Start_Player[4].NowMp);
    printf(" ▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃    \n");
    printf(" ▏   ---ItemList\n");
    printf(" ▏\n");
    printf(" ▏  0.초심자의 HP포션 : %2d개   3.초심자의 MP포션 : %2d개   6.초심자의 ALL포션 : %2d개   9.부활의 깃털 : %2d개\n", itemList[0], itemList[3], itemList[6], itemList[9]);
    printf(" ▏  1.중급자의 HP포션 : %2d개   4.중급자의 MP포션 : %2d개   7.중급자의 ALL포션 : %2d개   10.텐트 : %2d개\n", itemList[1], itemList[4], itemList[7], itemList[10]);
    printf(" ▏  2.상급자의 HP포션 : %2d개   5.상급자의 MP포션 : %2d개   8.상급자의 ALL포션 : %2d개\n", itemList[2], itemList[5], itemList[8]);
    printf(" ▏\n");
    printf(" ▏  1.공격      2.스킬      3.아이템      4.도망\n");
    printf(" ▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃    \n");
}

void battle(Class *Start_Player, int floor, int *itemList)
{
    srand(time(NULL));
    int mobNum = rand() % 7; // 몬스터수
    char *monster[11] = {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "};

    char *playericon[5] = {"■", "■", "■", "■", "■"}; //플레이어 아이콘

    for (int i = 0; i <= mobNum; i++) //몹 개수만큼 반복
    {
        if (i < mobNum)
            *(monster + i) = "😡";
        else if (i == mobNum) // 마지막에 보스 출력
            *(monster + i) = "👹";
    }
    int mobHp[10] = {
        0,
    };
    for (int j = 0; j <= mobNum; j++)
    {
        if (j < mobNum)
            mobHp[j] = rand() % 801 + 200;
        else if (j == mobNum)
            switch (floor)
            {
            case 1:
                mobHp[j] = rand() % 10001 + 25000; // floor에 따라 바뀌어야함, 1층보스
                break;
            case 2:
                mobHp[j] = rand() % 10001 + 45000;
                break;
            case 3:
                mobHp[j] = rand() % 10001 + 65000;
                break;
            case 4:
                mobHp[j] = rand() % 10001 + 75000;
                break;
            case 5:
                mobHp[j] = rand() % 10001 + 85000;
                break;
            }
    }
    int select; // 공격선택
    int person = 0, guard = 5;
    int attack;      // 플레이어 공격임시값
    int skill = 200; // 플레이어 스킬임시값

    int i = 0;
    while (1)
    {
        battleUI(monster, playericon, Start_Player, mobHp, itemList);
        while (person < guard)
        {
            if (Start_Player[person].NowHp > 0)
            {               
                printf("%s의 차례, 선택하세요\t", Start_Player[person].name);
                scanf("%d", &select);
                getchar();
                if (select == 1)
                {
                    switch (Start_Player[person].class_count)
                    {
                    case 0: // 전사
                        attack = Start_Player[person].Damage;
                        break;
                    case 1: // 백법사
                        attack = Start_Player[person].Damage;
                        break;
                    case 2: // 흑법사
                        attack = Start_Player[person].Damage;
                        break;
                    case 3: // 적법사
                        attack = Start_Player[person].Damage;
                        break;
                    case 4: // 궁수
                        attack = Start_Player[person].Damage;
                        break;
                    case 5: // 검사
                        attack = Start_Player[person].Damage;
                        break;
                    }
                    if (*(mobHp + i) > 0)
                    {
                        printf("일반공격\n");
                        *(mobHp + i) -= attack; //일반공격
                        printf("데미지 %d!\n", attack);
                        usleep(350000);
                        person++;
                        system("clear");
                        if (*(mobHp + i) <= 0 && i == mobNum)
                        {
                            printf("보스 클리어\n");
                            Get_Exp(Start_Player);
                            usleep(350000);
                            system("clear");
                            if (floor < 5)
                            { // 경험치, 레벨업
                                return;
                            }
                            else if (floor == 5)
                            {
                                printf("YOU WIN!\n");
                                sleep(2);
                                exit(1);
                            }
                        }
                        break;
                    }
                    else if (*(mobHp + i) <= 0 && i < mobNum)
                    {
                        switch (Start_Player[person].class_count)
                        {
                        case 0: // 전사
                            attack = Start_Player[person].Damage;
                            break;
                        case 1: // 백법사
                            attack = Start_Player[person].Damage;
                            break;
                        case 2: // 흑법사
                            attack = Start_Player[person].Damage;
                            break;
                        case 3: // 적법사
                            attack = Start_Player[person].Damage;
                            break;
                        case 4: // 궁수
                            attack = Start_Player[person].Damage;
                            break;
                        case 5: // 검사
                            attack = Start_Player[person].Damage;
                            break;
                        }
                        printf("일반공격\n");
                        *(mobHp + (i + 1)) -= attack;
                        printf("데미지 %d!\n", attack);
                        usleep(350000);
                        person++;
                        i++;
                        system("clear");
                        if (*(mobHp + i) <= 0 && i == mobNum)
                        {
                            printf("보스 클리어\n");
                            Get_Exp(Start_Player);
                            usleep(350000);
                            system("clear");
                            if (floor < 5)
                            { // 경험치,레벨업
                                return;
                            }
                            else if (floor == 5)
                            {
                                printf("YOU WIN!\n");
                                sleep(2);
                                exit(1);
                            }
                        }
                        break;
                    }
                }
                else if (select == 2)
                {
                    int skillSelect;
                    if (*(mobHp + i) > 0)
                    {
                        switch (Start_Player[person].class_count)
                        {
                        case 0: // 전사
                            printf("스킬을 쓸 수 없는 클래스입니다\n");
                            sleep(1);
                            break;
                        case 1: // 백법사
                            printf("스킬을 선택하세요\n1. 힐 2. 그레이터힐 3. 힐올\n");
                            int classSelect;
                            scanf("%d", &skillSelect);
                            getchar();
                            if (skillSelect == 1)
                            {
                                printf("클래스를 선택하세요\n0) 전사, 1) 백법사, 2) 흑법사, 3) 적법사, 4) 궁수, 5) 검사\n");
                                scanf("%d", &classSelect);
                                int heal = rand() % 41 + 30;
                                printf("HP를 %d%% 회복했습니다.\n", heal);
                                Start_Player[classSelect].NowHp = Start_Player[classSelect].MaxHp * (100 + heal) / 100;
                                if (Start_Player[classSelect].MaxHp < Start_Player[classSelect].NowHp)
                                    Start_Player[classSelect].NowHp = Start_Player[classSelect].MaxHp;
                            }
                            else if (skillSelect == 2)
                            {
                                if (Start_Player[person].Level > 14)
                                {
                                    printf("클래스를 선택하세요\n 0) 전사, 1) 백법사, 2) 흑법사, 3) 적법사, 4) 궁수, 5) 검사\n");
                                    scanf("%d", &classSelect);
                                    getchar();
                                    int heal = rand() % 41 + 60;
                                    printf("HP를 %d%% 회복했습니다.\n", heal);
                                    Start_Player[classSelect].NowHp = Start_Player[classSelect].MaxHp * (100 + heal) / 100;
                                    if (Start_Player[classSelect].MaxHp < Start_Player[classSelect].NowHp)
                                        Start_Player[classSelect].NowHp = Start_Player[classSelect].MaxHp;
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            else if (skillSelect == 3)
                            {
                                if (Start_Player[person].Level > 29)
                                {
                                    int heal = rand() % 41 + 40;
                                    printf("HP를 %d%% 회복했습니다.\n", heal);
                                    for (int i = 0; i < 5; i++)
                                    {
                                        Start_Player[classSelect].NowHp = Start_Player[classSelect].MaxHp * (100 + heal) / 100;
                                        if (Start_Player[classSelect].MaxHp < Start_Player[classSelect].NowHp)
                                            Start_Player[classSelect].NowHp = Start_Player[classSelect].MaxHp;
                                    }
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            break;

                        case 2: // 흑법사
                            printf("스킬을 선택하세요\n1. 파이어볼 2. 파이어월 3. 썬더브레이커 4.블리자드\n");

                            scanf("%d", &skillSelect);
                            getchar();
                            if (skillSelect == 1)
                            {
                                skill = Start_Player[person].Damage * 1.3;
                                printf("파이어볼\n");
                                *(mobHp + i) -= skill;
                                printf("데미지 %d!\n", skill);
                                usleep(350000);
                            }
                            else if (skillSelect == 2)
                            {
                                if (Start_Player[person].Level > 14)
                                {
                                    int plus = rand() % 21 + 50;
                                    skill = Start_Player[person].Damage * (100 + plus) / 100;
                                    printf("파이어월\n");
                                    for (int i = 0; i <= mobNum; i++)
                                    {
                                        *(mobHp + i) -= skill;
                                    }
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            else if (skillSelect == 3)
                            {
                                if (Start_Player[person].Level > 19)
                                {
                                    int plus = rand() % 21 + 50;
                                    skill = Start_Player[person].Damage * (100 + plus) / 100;
                                    printf("썬더브레이커\n");
                                    for (int i = 0; i <= mobNum; i++)
                                    {
                                        *(mobHp + i) -= skill;
                                    }
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            else if (skillSelect == 4)
                            {
                                if (Start_Player[person].Level > 24)
                                {
                                    int plus = rand() % 21 + 50;
                                    skill = Start_Player[person].Damage * (100 + plus) / 100;
                                    printf("블리자드\n");
                                    for (int i = 0; i <= mobNum; i++)
                                    {
                                        *(mobHp + i) -= skill;
                                    }
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            break;
                        case 3: // 적법사
                            printf("스킬을 선택하세요\n1. 공격력업 2.방어력업 3.맵핵\n");

                            scanf("%d", &skillSelect);
                            getchar();
                            if (skillSelect == 1)
                            {
                                if (Start_Player[person].Level > 0)
                                {
                                    int plus = rand() % 21 + 50;
                                    for (int i = 0; i < 5; i++)
                                    {
                                        Start_Player[i].Damage *= (100 + plus) / 100;
                                    }
                                    printf("공격력업확인\n");
                                    sleep(1);
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            else if (skillSelect == 2)
                            {
                                if (Start_Player[person].Level > 14)
                                {
                                    for (int i = 0; i < 5; i++)
                                    {
                                        Start_Player[i].DP *= 1.5;
                                    }
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            else if (skillSelect == 3)
                            {
                                if (Start_Player[person].Level > 29)
                                {
                                    // printf("던전 위치 x좌표 : %d, y좌표 : %d\n", dungeon_x, dungeon_y);
                                    printf("던전 위치 x좌표 : %d, y좌표 : %d\n", 0, 0);
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            break;
                        case 4: // 궁수
                            printf("스킬을 선택하세요\n1. 집중타 2. 듀얼샷 3. 마스터샷\n");

                            scanf("%d", &skillSelect);
                            getchar();
                            if (skillSelect == 1)
                            {
                                if (Start_Player[person].Level > 0)
                                {
                                    int plus = rand() % 31 + 20;
                                    skill = Start_Player[person].Damage * (100 + plus) / 100;
                                    printf("집중타\n");
                                    *(mobHp + i) -= skill;
                                    printf("데미지 %d!\n", skill);
                                    usleep(350000);
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            else if (skillSelect == 2)
                            {
                                if (Start_Player[person].Level > 14)
                                {
                                    int plus = rand() % 21 + 40;
                                    skill = Start_Player[person].Damage * (100 + plus) / 100;
                                    printf("듀얼샷\n");
                                    *(mobHp + i) -= skill;
                                    printf("데미지 %d!\n", skill);
                                    usleep(350000);
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            else if (skillSelect == 3)
                            {
                                if (Start_Player[person].Level > 19)
                                {
                                    int plus = rand() % 21 + 50;
                                    skill = Start_Player[person].Damage * (100 + plus) / 100;
                                    printf("마스터샷\n");
                                    *(mobHp + i) -= skill;
                                    printf("데미지 %d!\n", skill);
                                    usleep(350000);
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            break;
                        case 5: // 검사
                            printf("스킬을 선택하세요\n1. 검마법\n");

                            scanf("%d", &skillSelect);
                            getchar();

                            if (skillSelect == 1)
                            {
                                if (Start_Player[person].Level > 0)
                                {
                                    int plus = rand() % 49 + 2;
                                    skill = Start_Player[person].Damage * plus;
                                    printf("검마법\n");
                                    *(mobHp + i) -= skill;
                                    printf("데미지 %d!\n", skill);
                                    usleep(350000);
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            break;
                        }

                        person++;
                        system("clear");

                        if (*(mobHp + i) <= 0 && i < mobNum)
                        {
                            i++;
                        }
                        else if (*(mobHp + i) <= 0 && i == mobNum)
                        {
                            printf("보스 클리어\n");
                            Get_Exp(Start_Player);
                            usleep(350000);
                            system("clear");
                            if (floor < 5)
                            { //경험치, 레벨업
                                return;
                            }
                            else if (floor == 5)
                            {
                                printf("YOU WIN!\n");
                                sleep(2);
                                exit(1);
                            }
                        }
                        break;
                    }
                }
                else if (select == 3)
                {
                    itemUse(itemList, Start_Player, person);
                    person++;
                    break;
                }
                else if (select == 4)
                {
                    int run = rand() % 100;
                    if (run < 30)
                    {
                        printf("도망성공\n");
                        sleep(1);
                        system("clear");
                        return;
                    }
                    else
                    {
                        printf("도망실패\n");
                        sleep(1);
                        system("clear");
                        person++;
                        break;
                    }
                }
            }
            else if (Start_Player[person].NowHp <= 0)
            {
                switch (person)
                {
                case 4:
                    if (Start_Player[0].NowHp <= 0 && Start_Player[1].NowHp <= 0 && Start_Player[2].NowHp <= 0 && Start_Player[3].NowHp <= 0 && Start_Player[4].NowHp <= 0)
                    { // 플레이어 모두 죽음 게임 오버 엔딩
                        system("clear");
                        printf("game over\n");
                        sleep(2);
                        exit(1);
                    }
                default:
                    person++;
                }
            }
        }

        if (person == 5)
        {
            i = 0;
            while (i < mobNum + 1)
            {
                battleUI(monster, playericon, Start_Player, mobHp, itemList);
                int mobAttack = rand() % 5 + 10; // 몹 공격임시값
                int mobSkill = rand() % 100 + 0; // 몹 스킬임시값
                int bossAttack, bossSkill;
                char *bossName[5];
                char *bossSkillName[5];
                switch (floor)
                {
                case 1:
                    bossAttack = 50; // rand()%200+100;
                    bossSkill = 50;  // rand()%300+100;
                    bossName[0] = "리상혀기";
                    bossSkillName[0] = "과제폭탄";
                    break;
                case 2:
                    bossAttack = 50; // rand()%300+100;
                    bossSkill = 50;  // rand()%400+100;
                    bossName[1] = "또리우홍걸";
                    bossSkillName[1] = "진도 나가기";
                    break;
                case 3:
                    bossAttack = 50; // rand()%400+100;
                    bossSkill = 50;  // rand()%500+100;
                    bossName[2] = "쭈니형";
                    bossSkillName[2] = "노래 부르기";
                    break;
                case 4:
                    bossAttack = 50; // rand()%500+100;
                    bossSkill = 50;  // rand()%600+100;
                    bossName[3] = "코로나일구공주";
                    bossSkillName[3] = "마스크";
                    break;
                case 5:
                    bossAttack = 50; // rand()%600+100;
                    bossSkill = 50;  // rand()%700+100;
                    bossName[4] = "로드오브복이";
                    bossSkillName[4] = "콱마쌔리마";
                    break;
                } // 보스 공격임시값
                int randomAttack = rand() % 5;
                int selectAttack = rand() % 10;
                if (i < mobNum)
                {
                    if (*(mobHp + i) > 0 && Start_Player[randomAttack].NowHp > 0 && selectAttack < 7)
                    {
                        Start_Player[randomAttack].NowHp -= mobAttack;
                        i++;
                        sleep(1);
                        printf("일반몬스터의 일반공격 %s가 데미지 %d을(를) 입었다!\n", Start_Player[randomAttack].name, mobAttack);
                        sleep(2);
                        system("clear");
                    }
                    else if (*(mobHp + i) > 0 && Start_Player[randomAttack].NowHp > 0 && selectAttack > 6)
                    {
                        Start_Player[randomAttack].NowHp -= mobSkill;
                        i++;
                        sleep(1);
                        printf("일반몬스터의 스킬공격 %s가 데미지 %d을(를) 입었다!\n", Start_Player[randomAttack].name, mobSkill);
                        sleep(2);
                        system("clear");
                    }
                    else if (*(mobHp + i) <= 0)
                    {
                        i++;
                        system("clear");
                    }
                    else if (Start_Player[randomAttack].NowHp <= 0)
                    {
                        system("clear");
                        if (Start_Player[0].NowHp <= 0 && Start_Player[1].NowHp <= 0 && Start_Player[2].NowHp <= 0 && Start_Player[3].NowHp <= 0 && Start_Player[4].NowHp <= 0)
                        { // 플레이어 모두 죽음 게임 오버 엔딩
                            printf("game over\n");
                            sleep(2);
                            exit(1);
                        }
                    }
                }
                else if (i == mobNum)
                {
                    if (*(mobHp + i) > 0 && Start_Player[randomAttack].NowHp > 0 && selectAttack > 6)
                    {
                        Start_Player[randomAttack].NowHp -= bossAttack;
                        sleep(1);
                        printf("%s의 일반공격 %s가 데미지 %d을(를) 입었다!\n", bossName[floor - 1], Start_Player[randomAttack].name, bossAttack);
                        sleep(2);
                        system("clear");
                        person = 0;
                        i = 0;
                        break;
                    }
                    else if (*(mobHp + i) > 0 && Start_Player[randomAttack].NowHp > 0 && selectAttack < 7)
                    {
                        Start_Player[randomAttack].NowHp -= bossSkill;
                        sleep(1);
                        printf("%s의 %s공격 %s가 데미지 %d을(를) 입었다!\n", bossName[floor - 1], bossSkillName[floor - 1], Start_Player[randomAttack].name, bossSkill);
                        sleep(2);
                        system("clear");
                        person = 0;
                        i = 0;
                        break;
                    }
                    else if (Start_Player[randomAttack].NowHp <= 0)
                    {
                        system("clear");
                    }
                }
            }
        }
        continue;
    }
}
void nomalbattleUI(char **monster, char **playericon, Class *Start_Player, int *nomalmobHp, int *itemList) //일반몹 전투ui
{
    for (int i = 0; i < 5; i++)
    {
        if (Start_Player[i].NowHp < 0) // hp 0되면 0으로 표시
            Start_Player[i].NowHp = 0;
    }
    for (int i = 0; i < 10; i++)
    {
        if (*(nomalmobHp + i) < 0)
            *(nomalmobHp + i) = 0;
    }
    printf(" ▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃\n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏              %s                %s                 %s                %s                 %s                                            \n", monster[0], monster[1], monster[2], monster[3], monster[4]);
    printf(" ▏                %d              %d               %d              %d                %d                                                 \n", *nomalmobHp, *(nomalmobHp + 1), *(nomalmobHp + 2), *(nomalmobHp + 3), *(nomalmobHp + 4));
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                       \n");
    printf(" ▏              %s                 %s                 %s                %s                %s                                             \n", monster[5], monster[6], monster[7], monster[8], monster[9]);
    printf(" ▏                %d               %d                %d                %d            %d                                                 \n", *(nomalmobHp + 5), *(nomalmobHp + 6), *(nomalmobHp + 7), *(nomalmobHp + 8), *(nomalmobHp + 9));
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏            클래스1            클래스2            클래스3            클래스4           클래스5                                          \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏               %s                  %s                  %s                 %s                %s                                            \n", (playericon[0]), *(playericon + 1), *(playericon + 2), *(playericon + 3), *(playericon + 4));
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▏                                                                                                                                      \n");
    printf(" ▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃  \n");
    printf(" ▏         %-10s                  %-10s                  %-10s                 %-10s                 %-10s \n", Start_Player[0].name, Start_Player[1].name, Start_Player[2].name, Start_Player[3].name, Start_Player[4].name);
    printf(" ▏         %-10s                  %-10s                  %-10s                 %-10s                 %-10s \n", Start_Player[0].class_name, Start_Player[1].class_name, Start_Player[2].class_name, Start_Player[3].class_name, Start_Player[4].class_name);
    printf(" ▏         HP\\ %d                HP\\ %d                HP\\ %d               HP\\ %d               HP\\ %d           \n", Start_Player[0].NowHp, Start_Player[1].NowHp, Start_Player[2].NowHp, Start_Player[3].NowHp, Start_Player[4].NowHp);
    printf(" ▏         MP\t                  MP\t                 MP\t                MP\t                 MP\t           \n");
    printf(" ▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃    \n");
    printf(" ▏   ---ItemList\n");
    printf(" ▏\n");
    printf(" ▏  0.초심자의 HP포션 : %2d개   3.초심자의 MP포션 : %2d개   6.초심자의 ALL포션 : %2d개   9.부활의 깃털 : %2d개\n", itemList[0], itemList[3], itemList[6], itemList[9]);
    printf(" ▏  1.중급자의 HP포션 : %2d개   4.중급자의 MP포션 : %2d개   7.중급자의 ALL포션 : %2d개   10.텐트 : %2d개\n", itemList[1], itemList[4], itemList[7], itemList[10]);
    printf(" ▏  2.상급자의 HP포션 : %2d개   5.상급자의 MP포션 : %2d개   8.상급자의 ALL포션 : %2d개\n", itemList[2], itemList[5], itemList[8]);
    printf(" ▏\n");
    printf(" ▏  1.공격      2.스킬      3.아이템      4.도망\n");
    printf(" ▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃    \n");
}

void nomalbattle(Class *Start_Player, int *itemList, int playerX, int playerY, int dungeon_x, int dungeon_y, int floor) //일반몹 전투 함수
{
    srand(time(NULL));
    int mobamount = rand() % 10 + 1; // 몬스터수
    char *monster[11] = {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "};
    char mobSkillName[13];
    char *playericon[5] = {"■", "■", "■", "■", "■"}; //플레이어 아이콘

    for (int i = 0; i <= mobamount; i++) //몹 개수만큼 반복
    {
        if ((playerX >= 1 && playerX <= 10) && (playerY >= 1 && playerY <= 10)) //불맵
        {
            *(monster + i) = "😡";
            strcpy(mobSkillName, "불뿌리기");
        }
        else if ((playerX >= 1 && playerX <= 10) && (playerY >= 11 && playerX <= 21)) //눈맵
        {
            *(monster + i) = "❄️";
            strcpy(mobSkillName, "눈뿌리기");
        }
        else if ((playerX >= 11 && playerX <= 21) && (playerY >= 1 && playerY <= 10)) //풀맵
        {
            *(monster + i) = "🐸";
            strcpy(mobSkillName, "풀뿌리기");
        }
        else if ((playerX >= 11 && playerX <= 21) && (playerX >= 11 && playerX <= 21)) //물맵
        {
            *(monster + i) = "🐳";
            strcpy(mobSkillName, "물뿌리기");
        }
    }
    int nomalmobHp[10] = {
        0,
    };
    for (int j = 0; j <= mobamount; j++)
    {
        //  if( j<mobamount )
        nomalmobHp[j] = rand() % 901 + 100;
    }

    int select; // 공격선택
    int person = 0;
    int attack = 100; // 플레이어 공격임시값
    int skill = 200;  // 플레이어 스킬임시값

    int i = 0;
    while (1)
    {
        nomalbattleUI(monster, playericon, Start_Player, nomalmobHp, itemList);

        while (person < 5)
        {
            if (Start_Player[person].NowHp > 0)
            {

                printf("%s의 차례, 선택하세요\t", Start_Player[person].name);
                scanf("%d", &select);
                getchar();

                if (select == 1)
                {
                    if (*(nomalmobHp + i) > 0)
                    {
                        switch (Start_Player[person].class_count)
                        {
                        case 0: // 전사
                            attack = Start_Player[person].Damage;
                            break;
                        case 1: // 백법사
                            attack = Start_Player[person].Damage;
                            break;
                        case 2: // 흑법사
                            attack = Start_Player[person].Damage;
                            break;
                        case 3: // 적법사
                            attack = Start_Player[person].Damage;
                            break;
                        case 4: // 궁수
                            attack = Start_Player[person].Damage;
                            break;
                        case 5: // 검사
                            attack = Start_Player[person].Damage;
                            break;
                        }
                        //
                        printf("일반공격\n");
                        *(nomalmobHp + i) -= attack; //일반공격
                        printf("데미지 %d!\n", attack);
                        usleep(350000);
                        if (*(nomalmobHp + i) <= 0)
                        {
                            i++;
                            if (i > mobamount)
                            {
                                printf("전투종료!\n");
                                Get_Exp(Start_Player);
                                sleep(1);
                                return;
                            }
                        }
                        person++;
                        system("clear");
                        break;
                    }
                }
                else if (select == 2)
                {
                    int skillSelect;
                    if (*(nomalmobHp + i) > 0)
                    {
                        switch (Start_Player[person].class_count)
                        {
                        case 0: // 전사
                            printf("스킬을 쓸 수 없는 클래스입니다\n");
                            sleep(1);
                            break;
                        case 1: // 백법사
                            printf("스킬을 선택하세요\n1. 힐 2. 그레이터힐 3. 힐올\n");
                            int classSelect;
                            scanf("%d", &skillSelect);
                            getchar();
                            if (skillSelect == 1)
                            {
                                printf("클래스를 선택하세요\n0) 전사, 1) 백법사, 2) 흑법사, 3) 적법사, 4) 궁수, 5) 검사\n");
                                scanf("%d", &classSelect);
                                int heal = rand() % 41 + 30;
                                printf("HP를 %d%% 회복했습니다.\n", heal);
                                Start_Player[classSelect].NowHp = Start_Player[classSelect].MaxHp * (100 + heal) / 100;
                                if (Start_Player[classSelect].MaxHp < Start_Player[classSelect].NowHp)
                                    Start_Player[classSelect].NowHp = Start_Player[classSelect].MaxHp;
                            }
                            else if (skillSelect == 2)
                            {
                                if (Start_Player[person].Level > 14)
                                {
                                    printf("클래스를 선택하세요\n 0) 전사, 1) 백법사, 2) 흑법사, 3) 적법사, 4) 궁수, 5) 검사\n");
                                    scanf("%d", &classSelect);
                                    getchar();
                                    int heal = rand() % 41 + 60;
                                    printf("HP를 %d%% 회복했습니다.\n", heal);
                                    Start_Player[classSelect].NowHp = Start_Player[classSelect].MaxHp * (100 + heal) / 100;
                                    if (Start_Player[classSelect].MaxHp < Start_Player[classSelect].NowHp)
                                        Start_Player[classSelect].NowHp = Start_Player[classSelect].MaxHp;
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            else if (skillSelect == 3)
                            {
                                if (Start_Player[person].Level > 29)
                                {
                                    int heal = rand() % 41 + 40;
                                    printf("HP를 %d%% 회복했습니다.\n", heal);
                                    for (int i = 0; i < 5; i++)
                                    {
                                        Start_Player[classSelect].NowHp = Start_Player[classSelect].MaxHp * (100 + heal) / 100;
                                        if (Start_Player[classSelect].MaxHp < Start_Player[classSelect].NowHp)
                                            Start_Player[classSelect].NowHp = Start_Player[classSelect].MaxHp;
                                    }
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            break;

                        case 2: // 흑법사
                            printf("스킬을 선택하세요\n1. 파이어볼 2. 파이어월 3. 썬더브레이커 4.블리자드\n");

                            scanf("%d", &skillSelect);
                            getchar();
                            if (skillSelect == 1)
                            {
                                skill = Start_Player[person].Damage * 1.3;
                                printf("파이어볼\n");
                                *(nomalmobHp + i) -= skill;
                                printf("데미지 %d!\n", skill);
                                usleep(350000);
                            }
                            else if (skillSelect == 2)
                            {
                                if (Start_Player[person].Level > 14)
                                {
                                    int plus = rand() % 21 + 50;
                                    skill = Start_Player[person].Damage * (100 + plus) / 100;
                                    printf("파이어월\n");
                                    for (int i = 0; i <= mobamount; i++)
                                    {
                                        *(nomalmobHp + i) -= skill;
                                    }
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            else if (skillSelect == 3)
                            {
                                if (Start_Player[person].Level > 19)
                                {
                                    int plus = rand() % 21 + 50;
                                    skill = Start_Player[person].Damage * (100 + plus) / 100;
                                    printf("썬더브레이커\n");
                                    for (int i = 0; i <= mobamount; i++)
                                    {
                                        *(nomalmobHp + i) -= skill;
                                    }
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            else if (skillSelect == 4)
                            {
                                if (Start_Player[person].Level > 24)
                                {
                                    int plus = rand() % 21 + 50;
                                    skill = Start_Player[person].Damage * (100 + plus) / 100;
                                    printf("블리자드\n");
                                    for (int i = 0; i <= mobamount; i++)
                                    {
                                        *(nomalmobHp + i) -= skill;
                                    }
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            break;
                        case 3: // 적법사
                            printf("스킬을 선택하세요\n1. 공격력업 2.방어력업 3.맵핵\n");

                            scanf("%d", &skillSelect);
                            getchar();
                            if (skillSelect == 1)
                            {
                                if (Start_Player[person].Level > 0)
                                {
                                    int plus = rand() % 21 + 50;
                                    for (int i = 0; i < 5; i++)
                                    {
                                        Start_Player[i].Damage *= (100 + plus) / 100;
                                    }
                                    printf("공격력업확인\n");
                                    sleep(1);
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            else if (skillSelect == 2)
                            {
                                if (Start_Player[person].Level > 14)
                                {
                                    for (int i = 0; i < 5; i++)
                                    {
                                        Start_Player[i].DP *= 1.5;
                                    }
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            else if (skillSelect == 3)
                            {
                                if (Start_Player[person].Level > 29)
                                    printf("던전 위치 x좌표 : %d, y좌표 : %d\n", dungeon_x, dungeon_y);
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            break;
                        case 4: // 궁수
                            printf("스킬을 선택하세요\n1. 집중타 2. 듀얼샷 3. 마스터샷\n");

                            scanf("%d", &skillSelect);
                            getchar();
                            if (skillSelect == 1)
                            {
                                if (Start_Player[person].Level > 0)
                                {
                                    int plus = rand() % 31 + 20;
                                    skill = Start_Player[person].Damage * (100 + plus) / 100;
                                    printf("집중타\n");
                                    *(nomalmobHp + i) -= skill;
                                    printf("데미지 %d!\n", skill);
                                    usleep(350000);
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            else if (skillSelect == 2)
                            {
                                if (Start_Player[person].Level > 14)
                                {
                                    int plus = rand() % 21 + 40;
                                    skill = Start_Player[person].Damage * (100 + plus) / 100;
                                    printf("듀얼샷\n");
                                    *(nomalmobHp + i) -= skill;
                                    printf("데미지 %d!\n", skill);
                                    usleep(350000);
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            else if (skillSelect == 3)
                            {
                                if (Start_Player[person].Level > 19)
                                {
                                    int plus = rand() % 21 + 50;
                                    skill = Start_Player[person].Damage * (100 + plus) / 100;
                                    printf("마스터샷\n");
                                    *(nomalmobHp + i) -= skill;
                                    printf("데미지 %d!\n", skill);
                                    usleep(350000);
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            break;
                        case 5: // 검사
                            printf("스킬을 선택하세요\n1. 검마법\n");

                            scanf("%d", &skillSelect);
                            getchar();

                            if (skillSelect == 1)
                            {
                                if (Start_Player[person].Level > 0)
                                {
                                    int plus = rand() % 49 + 2;
                                    skill = Start_Player[person].Damage * plus;
                                    printf("검마법\n");
                                    *(nomalmobHp + i) -= skill;
                                    printf("데미지 %d!\n", skill);
                                    usleep(350000);
                                }
                                else
                                {
                                    printf("사용할 수 없는 레벨입니다.\n");
                                    sleep(1);
                                }
                            }
                            break;
                        }

                        person++;
                        system("clear");

                        if (*(nomalmobHp + i) <= 0 && i < mobamount)
                        {
                            i++;
                        }
                        else if (*(nomalmobHp + i) <= 0 && i == mobamount)
                        {
                            printf("보스 클리어\n");
                            Get_Exp(Start_Player);
                            usleep(350000);
                            system("clear");
                            if (floor < 5)
                            { //경험치, 레벨업
                                return;
                            }
                            else if (floor == 5)
                            {
                                printf("YOU WIN!\n");
                                sleep(2);
                                exit(1);
                            }
                        }
                        break;
                    }
                }
                else if (select == 3)
                {
                    // 아이템
                    itemUse(itemList, Start_Player, person);
                    person++;
                    break;
                }
                else if (select == 4)
                {
                    // 도망
                    int run = rand() % 100;
                    if (run < 30)
                    {
                        printf("도망성공\n");
                        sleep(1);
                        system("clear");
                        return;
                    }
                    else
                    {
                        printf("도망실패\n");
                        sleep(1);
                        system("clear");
                        person++;
                        break;
                    }
                }
            }
            else if (Start_Player[person].NowHp <= 0)
            {
                switch (person)
                {
                case 4:
                    if (Start_Player[0].NowHp <= 0 && Start_Player[1].NowHp <= 0 && Start_Player[2].NowHp <= 0 && Start_Player[3].NowHp <= 0 && Start_Player[4].NowHp <= 0)
                    { // 플레이어 모두 죽음 게임 오버 엔딩
                        printf("game over\n");
                        sleep(2);
                        exit(1);
                    }

                default:
                    person++;
                }
            }
        }

        if (person == 5)
        {
            int TURN = 0; //여기부터 i mobturn으로 바꿈
            while (TURN < mobamount + 1)
            {
                nomalbattleUI(monster, playericon, Start_Player, nomalmobHp, itemList);
                int mobAttack = rand() % 5 + 10; // 몹 공격임시값
                int mobSkill = rand() % 100 + 1; // 몹 스킬임시값
                int randomAttack = rand() % 5;
                int selectAttack = rand() % 3;

                if (*(nomalmobHp + TURN) > 0 && Start_Player[randomAttack].NowHp > 0 && selectAttack < 2)
                {
                    Start_Player[randomAttack].NowHp -= mobAttack;
                    TURN++;
                    printf("일반몬스터의 일반공격 %s가 데미지 %d을(를) 입었다!\n", Start_Player[randomAttack].name, mobAttack);
                    printf("TURN값:%d\n", TURN);
                    sleep(1);
                    system("clear");
                }
                else if (*(nomalmobHp + TURN) > 0 && Start_Player[randomAttack].NowHp > 0 && selectAttack == 2)
                {
                    Start_Player[randomAttack].NowHp -= mobSkill;
                    TURN++;
                    printf("일반몬스터의 %s %s가 데미지 %d을(를) 입었다!\n", mobSkillName, Start_Player[randomAttack].name, mobSkill);
                    printf("TURN값 :%d\n", TURN);
                    sleep(1);
                    system("clear");
                }
                else if (*(nomalmobHp + TURN) <= 0)
                {
                    TURN++;
                    printf("%d", TURN);
                    system("clear");
                }
                else if (Start_Player[randomAttack].NowHp <= 0)
                {
                    system("clear");
                    if (Start_Player[0].NowHp <= 0 && Start_Player[1].NowHp <= 0 && Start_Player[2].NowHp <= 0 && Start_Player[3].NowHp <= 0 && Start_Player[4].NowHp <= 0)
                    { // 플레이어 모두 죽음 게임 오버 엔딩
                        printf("game over\n");
                        sleep(1);
                        exit(1);
                    }
                }
                person = 0;
            }
        }
        continue;
    }
}

void Knightage(Class *Start_Player, int map_kind, int *itemList, int floor)
{
    srand(time(NULL));
    const char *knight[6];
    char *class[5];
    int all_knight = rand() % 3 + 1; //다른 수호단 랜덤 배정
    int all_class;
    int choose = 0, k = 5;
    char *knighticon[5] = {"■", "■", "■", "■", "■"};
    int knightHP[5];
    int attack = 0, enemy_attack = 0;
    int run = 0;
    int cnt = 0;
    int who_attack = 0;
    int person = 0;
    int i = 0, skill = 0;
    int knightNum = 5;
    // attack = rand()%21+50;//50~70 랜덤 공격

    Class Knight_Player[3];

    run = rand() % 3 + 1;

    if (map_kind == 1) //일반맵일때
    {
        for (int j = 0; j < 5; j++) // 15~20레벨 hp
        {
            knightHP[j] = rand() % 201 + 300;
        }
    }
    if (map_kind == 2) //던전 1층일때
    {
        for (int j = 0; j < 5; j++) // 20~25레벨hp
        {
            knightHP[j] = rand() % 201 + 500;
        }
    }
    if (map_kind == 3) //던전 2층 일때
    {
        for (int j = 0; j < 5; j++) // 25~30레벨 hp
        {
            knightHP[j] = rand() % 201 + 700;
        }
    }
    if (map_kind == 4) //던전 3층일때
    {
        for (int j = 0; j < 5; j++) // 30~35레벨hp
        {
            knightHP[j] = rand() % 201 + 900;
        }
    }
    if (map_kind == 5) //던전 4층일때
    {
        for (int j = 0; j < 5; j++) // 35~40레벨 hp
            knightHP[j] = rand() % 201 + 1100;
    }
    if (map_kind == 6) //던전 5층일때
    {
        for (int j = 0; j < 5; j++) // 40~45레벨 hp
            knightHP[j] = rand() % 201 + 1300;
    }

    if (all_knight == 1) //빛의 수호단
    {
        knight[0] = "성진";
        knight[1] = "재정";
        knight[2] = "명석";
        knight[3] = "진우";
        knight[4] = "도현";
        knight[5] = "빛의 수호대";
    }
    else if (all_knight == 2) //달의 수호대
    {
        knight[0] = "민식";
        knight[1] = "인선";
        knight[2] = "종욱";
        knight[3] = "준형";
        knight[4] = "은혁";
        knight[5] = "달의 수호대";
    }
    else //별의 수호대
    {
        knight[0] = "정빈";
        knight[1] = "가미";
        knight[2] = "현동";
        knight[3] = "승렬";
        knight[4] = "홍석";
        knight[5] = "별의 수호대";
    }

    

        class[0] = "백법사";        
        class[1] = "궁수";        
        class[2] = "흑법사";        
        class[3] = "전사";        
        class[4] = "검사";
      
    while (1)
    {
        while (1)
        {
            printf(" ▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃\n");
            printf(" ▏                                                                                                                                        \n");
            printf(" ▏    %s                                                                                                                                  \n", knight[5]);
            printf(" ▏                                                                                                                                        \n");
            printf(" ▏                                                                                                                                        \n");
            printf(" ▏                                                                                                                                        \n");
            printf(" ▏                                                                                                                                        \n");
            printf(" ▏                                                                                                                                        \n");
            printf(" ▏                                                                                                                                        \n");
            printf(" ▏                                                                                                                                        \n");
            printf(" ▏               %s                  %s                 %s                     %s                    %s                           \n", knighticon[0], knighticon[1], knighticon[2], knighticon[3], knighticon[4]);
            printf(" ▏              %3d                 %3d               %3d                  %3d                  %3d                                              \n", knightHP[0], knightHP[1], knightHP[2], knightHP[3], knightHP[4]);
            printf(" ▏              %s                   %s                  %s                %s                          %s                                           \n", knight[0], knight[1], knight[2], knight[3], knight[4]);
            printf(" ▏                                                                                                                                        \n");
            printf(" ▏                                                                                                                                        \n");
            printf(" ▏                                                                                                                                        \n");
            printf(" ▏                                                                                                                                        \n");
            printf(" ▏              %s                  %s                %s                %s                 %s                                             \n", class[0], class[1], class[2], class[3], class[4]);
            printf(" ▏                                                                                                                                        \n");
            printf(" ▏                                                                                                                                        \n");
            printf(" ▏                                                                                                                                        \n");
            printf(" ▏                                                                                                                                        \n");
            printf(" ▏                                                                                                                                        \n");
            printf(" ▏                                                                                                                                        \n");
            printf(" ▏                                                                                                                                        \n");
            printf(" ▏                                                                                                                                        \n");
            printf(" ▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃  \n");
            printf(" ▏             %s                     %s                             %s                      %s                   %s           \n", Start_Player[0].name, Start_Player[1].name, Start_Player[2].name, Start_Player[3].name, Start_Player[4].name);
            printf(" ▏             %s                     %s                             %s                       %s                   %s                    \n", Start_Player[0].class_name, Start_Player[1].class_name, Start_Player[2].class_name, Start_Player[3].class_name, Start_Player[4].class_name);
            printf(" ▏         HP%3d\t                  HP%3d\t                       HP%3d\t                     HP%3d\t                  HP%3d\t                            \n", Start_Player[0].NowHp, Start_Player[1].NowHp, Start_Player[2].NowHp, Start_Player[3].NowHp, Start_Player[4].NowHp);
            printf(" ▏         MP%3d\t                  MP%3d\t                       MP%3d\t                     MP%3d\t                  MP%3d\t                            \n", Start_Player[0].NowMp, Start_Player[1].NowMp, Start_Player[2].NowMp, Start_Player[3].NowMp, Start_Player[4].NowMp);
            printf(" ▏                                                                                                                                         \n");
            printf(" ▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃    \n");
            printf(" ▏   ---ItemList\n");
            printf(" ▏\n");
            printf(" ▏  0.초심자의 HP포션 : %2d개   3.초심자의 MP포션 : %2d개   6.초심자의 ALL포션 : %2d개   9.부활의 깃털 : %2d개\n", itemList[0], itemList[3], itemList[6], itemList[9]);
            printf(" ▏  1.중급자의 HP포션 : %2d개   4.중급자의 MP포션 : %2d개   7.중급자의 ALL포션 : %2d개   10.텐트 : %2d개\n", itemList[1], itemList[4], itemList[7], itemList[10]);
            printf(" ▏  2.상급자의 HP포션 : %2d개   5.상급자의 MP포션 : %2d개   8.상급자의 ALL포션 : %2d개\n", itemList[2], itemList[5], itemList[8]);
            printf(" ▏\n");
            printf(" ▏  1.공격      2.스킬      3.아이템      4.도망\n");
            printf(" ▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃    \n");

            printf("무엇을 할까요? : ");
            scanf("%d", &choose);
            getchar();
            if (choose == 1)
            {          
                printf("일반공격!\n");           // 우리팀이 적팀 공격                
              
                while(knightHP[i] <= 0)
                {                    
                    i++;
                }            
                
                attack = Start_Player[person].Damage;
                knightHP[i] -= attack;
                
                printf("%d의 데미지를 입혔다!\n", attack);
                if(knightHP[i] <= 0)
                {
                    knightHP[i] = 0;                    
                }  
                usleep(500000);
                system("clear");
                person++;        
            }
            else if (choose == 2)
            {
                int skillSelect;
                if (*(knightHP + i) > 0)
                {
                    switch (Start_Player[person].class_count)
                    {
                    case 0: // 전사
                        printf("스킬을 쓸 수 없는 클래스입니다\n");
                        sleep(1);
                        break;
                    case 1: // 백법사
                        printf("스킬을 선택하세요\n1. 힐 2. 그레이터힐 3. 힐올\n");
                        int classSelect;
                        scanf("%d", &skillSelect);
                        getchar();
                        if (skillSelect == 1)
                        {
                            printf("클래스를 선택하세요\n0) 전사, 1) 백법사, 2) 흑법사, 3) 적법사, 4) 궁수, 5) 검사\n");
                            scanf("%d", &classSelect);
                            int heal = rand() % 41 + 30;
                            printf("HP를 %d%% 회복했습니다.\n", heal);
                            Start_Player[classSelect].NowHp = Start_Player[classSelect].MaxHp * (100 + heal) / 100;
                            if (Start_Player[classSelect].MaxHp < Start_Player[classSelect].NowHp)
                                Start_Player[classSelect].NowHp = Start_Player[classSelect].MaxHp;
                        }
                        else if (skillSelect == 2)
                        {
                            if (Start_Player[person].Level > 14)
                            {
                                printf("클래스를 선택하세요\n 0) 전사, 1) 백법사, 2) 흑법사, 3) 적법사, 4) 궁수, 5) 검사\n");
                                scanf("%d", &classSelect);
                                getchar();
                                int heal = rand() % 41 + 60;
                                printf("HP를 %d%% 회복했습니다.\n", heal);
                                Start_Player[classSelect].NowHp = Start_Player[classSelect].MaxHp * (100 + heal) / 100;
                                if (Start_Player[classSelect].MaxHp < Start_Player[classSelect].NowHp)
                                    Start_Player[classSelect].NowHp = Start_Player[classSelect].MaxHp;
                            }
                            else
                            {
                                printf("사용할 수 없는 레벨입니다.\n");
                                sleep(1);
                            }
                        }
                        else if (skillSelect == 3)
                        {
                            if (Start_Player[person].Level > 29)
                            {
                                int heal = rand() % 41 + 40;
                                printf("HP를 %d%% 회복했습니다.\n", heal);
                                for (int i = 0; i < 5; i++)
                                {
                                    Start_Player[classSelect].NowHp = Start_Player[classSelect].MaxHp * (100 + heal) / 100;
                                    if (Start_Player[classSelect].MaxHp < Start_Player[classSelect].NowHp)
                                        Start_Player[classSelect].NowHp = Start_Player[classSelect].MaxHp;
                                }
                            }
                            else
                            {
                                printf("사용할 수 없는 레벨입니다.\n");
                                sleep(1);
                            }
                        }
                        break;

                    case 2: // 흑법사
                        printf("스킬을 선택하세요\n1. 파이어볼 2. 파이어월 3. 썬더브레이커 4.블리자드\n");

                        scanf("%d", &skillSelect);
                        getchar();
                        if (skillSelect == 1)
                        {
                            skill = Start_Player[person].Damage * 1.3;
                            printf("파이어볼\n");
                            *(knightHP + i) -= skill;
                            printf("데미지 %d!\n", skill);
                            usleep(350000);
                        }
                        else if (skillSelect == 2)
                        {
                            if (Start_Player[person].Level > 14)
                            {
                                int plus = rand() % 21 + 50;
                                skill = Start_Player[person].Damage * (100 + plus) / 100;
                                printf("파이어월\n");
                                for (int i = 0; i <= knightNum; i++)
                                {
                                    *(knightHP + i) -= skill;
                                }
                            }
                            else
                            {
                                printf("사용할 수 없는 레벨입니다.\n");
                                sleep(1);
                            }
                        }
                        else if (skillSelect == 3)
                        {
                            if (Start_Player[person].Level > 19)
                            {
                                int plus = rand() % 21 + 50;
                                skill = Start_Player[person].Damage * (100 + plus) / 100;
                                printf("썬더브레이커\n");
                                for (int i = 0; i <= knightNum; i++)
                                {
                                    *(knightHP + i) -= skill;
                                }
                            }
                            else
                            {
                                printf("사용할 수 없는 레벨입니다.\n");
                                sleep(1);
                            }
                        }
                        else if (skillSelect == 4)
                        {
                            if (Start_Player[person].Level > 24)
                            {
                                int plus = rand() % 21 + 50;
                                skill = Start_Player[person].Damage * (100 + plus) / 100;
                                printf("블리자드\n");
                                for (int i = 0; i <= knightNum; i++)
                                {
                                    *(knightHP + i) -= skill;
                                }
                            }
                            else
                            {
                                printf("사용할 수 없는 레벨입니다.\n");
                                sleep(1);
                            }
                        }
                        break;
                    case 3: // 적법사
                        printf("스킬을 선택하세요\n1. 공격력업 2.방어력업 3.맵핵\n");

                        scanf("%d", &skillSelect);
                        getchar();
                        if (skillSelect == 1)
                        {
                            if (Start_Player[person].Level > 0)
                            {
                                int plus = rand() % 21 + 50;
                                for (int i = 0; i < 5; i++)
                                {
                                    Start_Player[i].Damage *= (100 + plus) / 100;
                                }
                                printf("공격력업확인\n");
                                sleep(1);
                            }
                            else
                            {
                                printf("사용할 수 없는 레벨입니다.\n");
                                sleep(1);
                            }
                        }
                        else if (skillSelect == 2)
                        {
                            if (Start_Player[person].Level > 14)
                            {
                                for (int i = 0; i < 5; i++)
                                {
                                    Start_Player[i].DP *= 1.5;
                                }
                            }
                            else
                            {
                                printf("사용할 수 없는 레벨입니다.\n");
                                sleep(1);
                            }
                        }
                        else if (skillSelect == 3)
                        {
                            if (Start_Player[person].Level > 29)
                            {
                                // printf("던전 위치 x좌표 : %d, y좌표 : %d\n", dungeon_x, dungeon_y);
                                printf("던전 위치 x좌표 : %d, y좌표 : %d\n", 0, 0);
                            }
                            else
                            {
                                printf("사용할 수 없는 레벨입니다.\n");
                                sleep(1);
                            }
                        }
                        break;
                    case 4: // 궁수
                        printf("스킬을 선택하세요\n1. 집중타 2. 듀얼샷 3. 마스터샷\n");

                        scanf("%d", &skillSelect);
                        getchar();
                        if (skillSelect == 1)
                        {
                            if (Start_Player[person].Level > 0)
                            {
                                int plus = rand() % 31 + 20;
                                skill = Start_Player[person].Damage * (100 + plus) / 100;
                                printf("집중타\n");
                                *(knightHP + i) -= skill;
                                printf("데미지 %d!\n", skill);
                                usleep(350000);
                            }
                            else
                            {
                                printf("사용할 수 없는 레벨입니다.\n");
                                sleep(1);
                            }
                        }
                        else if (skillSelect == 2)
                        {
                            if (Start_Player[person].Level > 14)
                            {
                                int plus = rand() % 21 + 40;
                                skill = Start_Player[person].Damage * (100 + plus) / 100;
                                printf("듀얼샷\n");
                                *(knightHP + i) -= skill;
                                printf("데미지 %d!\n", skill);
                                usleep(350000);
                            }
                            else
                            {
                                printf("사용할 수 없는 레벨입니다.\n");
                                sleep(1);
                            }
                        }
                        else if (skillSelect == 3)
                        {
                            if (Start_Player[person].Level > 19)
                            {
                                int plus = rand() % 21 + 50;
                                skill = Start_Player[person].Damage * (100 + plus) / 100;
                                printf("마스터샷\n");
                                *(knightHP + i) -= skill;
                                printf("데미지 %d!\n", skill);
                                usleep(350000);
                            }
                            else
                            {
                                printf("사용할 수 없는 레벨입니다.\n");
                                sleep(1);
                            }
                        }
                        break;
                    case 5: // 검사
                        printf("스킬을 선택하세요\n1. 검마법\n");

                        scanf("%d", &skillSelect);
                        getchar();

                        if (skillSelect == 1)
                        {
                            if (Start_Player[person].Level > 0)
                            {
                                int plus = rand() % 49 + 2;
                                skill = Start_Player[person].Damage * plus;
                                printf("검마법\n");
                                *(knightHP + i) -= skill;
                                printf("데미지 %d!\n", skill);
                                usleep(350000);
                            }
                            else
                            {
                                printf("사용할 수 없는 레벨입니다.\n");
                                sleep(1);
                            }
                        }
                        break;
                    }                  
                                  
                    person++;
                    system("clear"); 
                    if (*(knightHP + i) <= 0)
                    {
                        *(knightHP + i) = 0;
                        i++;
                    } 
               
                }
                else if (*(knightHP + i) <= 0)
                {
                    *(knightHP + i) = 0;
                    i++;
                } 
            }
            else if (choose == 3)
            {
                //아이템함수
                printf("%d\n\n", person);
                itemUse(itemList, Start_Player, person);
                person++;
                continue;
            }
            else if (choose == 4)
            {
                if (run == 1)
                {
                    printf("도망에 성공하였습니다\n");
                    usleep(500000);
                    system("clear");
                    return;
                }
                else if (run == 2 || run == 3)
                {
                    printf("도망에 실패하였습니다.\n");
                    continue;
                }
            }
            else
                continue;

            if (person % 5 == 0 && person != 0) //적팀이 우리팀 공격
            {
                i=0;
                person = 0;                
      
                for (int i = 0; i < 5; i++)
                {
                    int enemy_attack = rand() % 30 + 10; // 적수호대의 일반 공격
                    int enemy_action = rand() % 3; //적 수호대의 행동 0: 일반공격, 1: 스킬공격, 2: 아이템사용
                    int Who_attack = rand() % 5; //우리팀 중 누가 맞을지

                    if (i == 0 && knightHP[i]>0) //백마법사
                    {
                    
                        if(enemy_action == 1 || enemy_action == 0)
                        {
                            //수호대 0번의 스킬 공격
                            printf("%s가 힐을 썼습니다\n",class[i]);
                            knightHP[who_attack]+=100; //100회복
                            usleep(700000);
                        }
                        else if(enemy_action == 2)
                        {
                            printf("%s가 아이템을 사용하였습니다!\n",class[i]);
                            knightHP[i]+=100; //100회복
                            usleep(700000);
                        }
                    }
                    else if (i == 1 && knightHP[i]>0) //궁수 
                    {
                        if(enemy_action == 0)
                        {
                            if (Start_Player[Who_attack].NowHp > 0)
                            {
                                Start_Player[Who_attack].NowHp -= enemy_attack;
                                printf("%s이 %s의 공격을 받았다\n", Start_Player[Who_attack].name, class[i]);
                                if (Start_Player[Who_attack].NowHp <= 0)
                                {
                                    Start_Player[Who_attack].NowHp = 0;
                                    printf("%s이 쓰러졌습니다\n", Start_Player[0].name);
                                }
                                usleep(700000);                     
                            }
                            else if (Start_Player[Who_attack].NowHp <= 0)
                            {
                                printf("적의 공격이 빗나갔습니다!\n");
                                usleep(700000);
                            }
                        }
                        else if(enemy_action == 1)
                        {
                            //수호대 0번의 스킬 공격
                            printf("%s가 집중타를 사용하였습니다!\n",class[i]);
                            Start_Player[Who_attack].NowHp -= 50;
                            usleep(700000);
                        }
                        else if(enemy_action == 2)
                        {
                            printf("%s가 아이템을 사용하였습니다!\n",class[i]);
                            knightHP[i]+=100; //100회복
                            usleep(700000);
                        }
                    }
                    else if (i == 2 && knightHP[i]>0) //흑마법사
                    {
                        if(enemy_action == 0)
                        {
                            if (Start_Player[Who_attack].NowHp > 0)
                            {
                                Start_Player[Who_attack].NowHp -= enemy_attack;
                                printf("%s이 %s의 공격을 받았다\n", Start_Player[Who_attack].name, class[i]);
                                if (Start_Player[Who_attack].NowHp <= 0)
                                {
                                    Start_Player[Who_attack].NowHp = 0;
                                    printf("%s이 쓰러졌습니다\n", Start_Player[0].name);
                                }
                                usleep(700000);                     
                            }
                            else if (Start_Player[Who_attack].NowHp <= 0)
                            {
                                printf("적의 공격이 빗나갔습니다!\n");
                                usleep(700000);
                            }
                        }
                        else if(enemy_action == 1) //흑마법사
                        {
                            //수호대 0번의 스킬 공격
                            printf("%s가 파이어볼을 사용하였습니다!\n",class[i]);
                            Start_Player[Who_attack].NowHp -= 60;
                            usleep(700000);
                        }
                        else if(enemy_action == 2)
                        {
                            printf("%s가 아이템을 사용하였습니다!\n",class[i]);
                            knightHP[i]+=100; //100회복
                            usleep(700000);
                        }
                    }
                    else if (i == 3 && knightHP[i]>0) //전사 
                    {
                        if(enemy_action == 0 || enemy_action==1 )
                        {
                            if (Start_Player[Who_attack].NowHp > 0)
                            {
                                Start_Player[Who_attack].NowHp -= enemy_attack;
                                printf("%s이 %s의 공격을 받았다\n", Start_Player[Who_attack].name, class[i]);
                                if (Start_Player[Who_attack].NowHp <= 0)
                                {
                                    Start_Player[Who_attack].NowHp = 0;
                                    printf("%s이 쓰러졌습니다\n", Start_Player[0].name);
                                }
                                usleep(700000);                     
                            }
                            else if (Start_Player[Who_attack].NowHp <= 0)
                            {
                                printf("적의 공격이 빗나갔습니다!\n");
                                usleep(700000);
                            }
                        }
                        
                        else if(enemy_action == 2)
                        {
                            printf("%s가 아이템을 사용하였습니다!\n",class[i]);
                            knightHP[i]+=100; //100회복
                            usleep(700000);
                        }
                    }
                    else if (i == 4 && knightHP[i]>0) //검사
                    {
                        if(enemy_action == 0)
                        {
                            if (Start_Player[Who_attack].NowHp > 0)
                            {
                                Start_Player[Who_attack].NowHp -= enemy_attack;
                                printf("%s이 %s의 공격을 받았다\n", Start_Player[Who_attack].name, class[i]);
                                if (Start_Player[Who_attack].NowHp <= 0)
                                {
                                    Start_Player[Who_attack].NowHp = 0;
                                    printf("%s이 쓰러졌습니다\n", Start_Player[0].name);
                                }
                                usleep(700000);                     
                            }
                            else if (Start_Player[Who_attack].NowHp <= 0)
                            {
                                printf("적의 공격이 빗나갔습니다!\n");
                                usleep(700000);
                            }
                        }
                        else if(enemy_action == 1)
                        {
                            //수호대 5번의 스킬 공격
                            printf("%s가 검마법을 사용하였습니다!\n",class[i]);
                            Start_Player[Who_attack].NowHp -= 70;
                            usleep(700000);
                        }
                        else if(enemy_action == 2)
                        {
                            printf("%s가 아이템을 사용하였습니다!\n",class[i]);
                            knightHP[i]+=100; //100회복
                            usleep(700000);
                        }
                    }
                    
                }
            }

            if (knightHP[0] == 0 && knightHP[1] == 0 && knightHP[2] == 0 && knightHP[3] == 0 && knightHP[4] == 0)
            {
                printf("전투에 승리하였습니다.\n");
                Get_Exp(Start_Player);
                sleep(1);
                system("clear");
                return;
            }
            if (Start_Player[0].NowHp == 0 && Start_Player[1].NowHp == 0 && Start_Player[2].NowHp == 0 && Start_Player[3].NowHp == 0 && Start_Player[4].NowHp == 0)
            {
                printf("전투에 패배하였습니다.\n");
                sleep(1);
                system("clear");
                exit(1);
            }
        }
    } // while
}
